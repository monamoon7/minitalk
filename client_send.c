/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client_send.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mshaghaf <mshaghaf@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/17 14:23:03 by mona          #+#    #+#                 */
/*   Updated: 2025/08/17 18:05:11 by mona          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	send_bit(pid_t pid, int bit, const sigset_t *empty)
{
	g_got_ack = 0;
	if (bit)
	{
		if (kill(pid, SIGUSR2) == -1)
			return (err("kill error\n"));
	}
	else
	{
		if (kill(pid, SIGUSR1) == -1)
			return (err("kill error\n"));
	}
	while (!g_got_ack)
		sigsuspend(empty);
	return (0);
}

int	send_char(pid_t pid, unsigned char c, const sigset_t *empty)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (send_bit(pid, (c >> i) & 1, empty))
			return (1);
		i--;
	}
	return (0);
}

int	send_str(pid_t pid, const unsigned char *p, const sigset_t *empty)
{
	while (*p)
	{
		if (send_char(pid, *p, empty))
			return (1);
		p++;
	}
	if (send_char(pid, '\0', empty))
		return (1);
	return (0);
}
