/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mshaghaf <mshaghaf@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/13 17:58:30 by mona          #+#    #+#                 */
/*   Updated: 2025/08/17 16:10:01 by mona          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#include "minitalk.h"

static volatile sig_atomic_t	g_got_ack = 0;
static volatile sig_atomic_t	g_eom = 0;

static void	sig_handler(int signo)
{
	if (signo == SIGUSR1)
		g_got_ack = 1;
	else if (signo == SIGUSR2)
		g_eom = 1;
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

static void	send_char(pid_t pid, unsigned char c, const sigset_t *empty)
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
			sigsuspend(empty);
		i--;
	}
}

static void	send_str(pid_t pid, const unsigned char *p,
			const sigset_t *empty)
{
	while (*p)
		send_char(pid, *p++, empty);
	send_char(pid, '\0', empty);
}

int	main(int argc, char **argv)
{
	pid_t					pid;
	const unsigned char		*p;
	sigset_t				block;
	sigset_t				empty;

	if (argc != 3)
		return (err("Usage: ./client <server_pid> \"<message>\"\n"));
	if (install_handlers())
		return (1);
	if (parse_pid(argv[1], &pid))
		return (1);
	init_masks(&block, &empty);
	sigprocmask(SIG_BLOCK, &block, NULL);
	p = (const unsigned char *)argv[2];
	send_str(pid, p, &empty);
	while (!g_eom)
		sigsuspend(&empty);
	sigprocmask(SIG_UNBLOCK, &block, NULL);
	ft_putstr_fd("Delivered\n", 1);
	return (0);
}
