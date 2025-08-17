/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mshaghaf <mshaghaf@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/11 16:39:44 by mona          #+#    #+#                 */
/*   Updated: 2025/08/17 18:04:51 by mona          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static unsigned char	g_ch;
static int				g_bit;
static pid_t			g_client_pid;

static void	handle_complete_char(void)
{
	if (g_ch == 0)
	{
		write(1, "\n", 1);
		if (g_client_pid > 0)
			kill(g_client_pid, SIGUSR2);
	}
	else
	{
		write(1, &g_ch, 1);
		if (g_client_pid > 0)
			kill(g_client_pid, SIGUSR1);
	}
	g_ch = 0;
	g_bit = 0;
}

static void	sig_handler(int sig, siginfo_t *info, void *u)
{
	(void)u;
	if (info && info->si_pid != 0)
		g_client_pid = info->si_pid;
	if (sig == SIGUSR2)
		g_ch = (g_ch << 1) | 1;
	else
		g_ch = g_ch << 1;
	g_bit++;
	if (g_bit == 8)
		handle_complete_char();
	else if (g_client_pid > 0)
		kill(g_client_pid, SIGUSR1);
}

static int	setup_signals(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sa.sa_sigaction = sig_handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (ft_putstr_fd("sigaction error\n", 2), 1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (ft_putstr_fd("sigaction error\n", 2), 1);
	return (0);
}

int	main(void)
{
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	g_ch = 0;
	g_bit = 0;
	g_client_pid = 0;
	if (setup_signals())
		return (1);
	while (1)
		pause();
	return (0);
}
