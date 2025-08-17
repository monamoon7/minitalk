/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mshaghaf <mshaghaf@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/13 17:58:30 by mona          #+#    #+#                 */
/*   Updated: 2025/07/30 14:49:07 by mona          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "libft/libft.h"

void	send_char(pid_t pid, unsigned char c)
{
	int i = 7;

	while (i >= 0)
	{
		if ((c >> i) & 1) // if bit at pistion i is 1 
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100); //tiny delay so server doesn't miss signals
		i--;
	}
}

int main(int argc, char **argv)
{
	pid_t	server_pid;

	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./client <server_pid>\n", 2);
		return (1);
	}

	server_pid = (pid_t)atoi(argv[1]);

	send_char(server_pid, 'A');

	return (0);
}