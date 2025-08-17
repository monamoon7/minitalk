/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mshaghaf <mshaghaf@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/13 17:58:30 by mona          #+#    #+#                 */
/*   Updated: 2025/08/17 11:59:11 by mona          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile sig_atomic_t g_got_ack = 0;

static void	ack_handler(int signo)
{
	(void)signo;
	g_got_ack = 1; /* just flip the flag */
}

static int	install_ack_handler(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sa.sa_handler = ack_handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_putstr_fd("sigaction error (client)\n", 2);
		return (1);
	}
	return (0);
}

/* send bits MSB first to match server: SIGUSR2 = 1, SIGUSR1 = 0 */
void	send_char(pid_t pid, unsigned char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		g_got_ack = 0;
		if ((c >> i) & 1)
    		kill(pid, SIGUSR2);
		else
    		kill(pid, SIGUSR1);
		while (!g_got_ack)
    		pause();
		i--;
	}
}

static int	is_all_digits(const char *s)
{
	int	i;

	i = 0;
	if (!s || !s[0])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	pid_t		pid;
	const char	*msg;
	int			i;

	if (argc != 3)
		return (ft_putstr_fd("Usage: ./client <server_pid> \"<message>\"\n", 2), 1);
	if (!is_all_digits(argv[1]))
		return (ft_putstr_fd("Error: bad PID\n", 2), 1);
	pid = (pid_t)ft_atoi(argv[1]);
	if (pid <= 0)
		return (ft_putstr_fd("Error: bad PID\n", 2), 1);
	if (install_ack_handler())
		return (1);
	msg = argv[2];
	i = 0;
	while (msg[i])
	{
		send_char(pid, (unsigned char)msg[i]);
		i++;
	}
	send_char(pid, '\n');
	return (0);
}

