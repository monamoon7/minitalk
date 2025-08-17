/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mshaghaf <mshaghaf@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/13 17:58:30 by mona          #+#    #+#                 */
/*   Updated: 2025/08/17 17:16:27 by mona          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_got_ack = 0;
volatile sig_atomic_t	g_eom = 0;

static void	sig_handler(int signo)
{
	if (signo == SIGUSR1)
		g_got_ack = 1;
	else if (signo == SIGUSR2)
	{
		g_eom = 1;
		g_got_ack = 1;
	}
}

static int	install_handlers(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = sig_handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		return (err("sigaction error (client)\n"));
	return (0);
}

static int	run_client(pid_t pid, const unsigned char *p)
{
	sigset_t	block;
	sigset_t	empty;

	if (kill(pid, 0) == -1)
		return (err("Error: Server PID not found\n"));
	init_masks(&block, &empty);
	sigprocmask(SIG_BLOCK, &block, NULL);
	if (send_str(pid, p, &empty))
	{
		sigprocmask(SIG_UNBLOCK, &block, NULL);
		return (1);
	}
	while (!g_eom)
		sigsuspend(&empty);
	sigprocmask(SIG_UNBLOCK, &block, NULL);
	ft_putstr_fd("Message delivered\n", 1);
	return (0);
}

int	main(int argc, char **argv)
{
	pid_t					pid;
	const unsigned char		*p;

	if (argc != 3)
		return (err("Usage: ./client <server_pid> \"<message>\"\n"));
	if (install_handlers())
		return (1);
	if (parse_pid(argv[1], &pid))
		return (1);
	p = (const unsigned char *)argv[2];
	return (run_client(pid, p));
}
