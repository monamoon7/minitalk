/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mshaghaf <mshaghaf@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/11 16:39:44 by mona          #+#    #+#                 */
/*   Updated: 2025/08/17 16:04:49 by mona          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	on_full_byte(pid_t pid, unsigned char *ch, int *bit)
{
	if (*ch == '\0')
		kill(pid, SIGUSR2);
	else
		write(1, ch, 1);
	*ch = 0;
	*bit = 0;
}

static void	signal_handler(int sig, siginfo_t *info, void *u)
{
	static unsigned char	ch = 0;
	static int				bit = 0;
	pid_t					src;

	(void)u;
	if (info)
		src = info->si_pid;
	else
		src = 0;
	ch <<= 1;
	if (sig == SIGUSR2)
		ch |= 1;
	bit++;
	if (bit == 8)
		on_full_byte(src, &ch, &bit);
	if (src > 0)
		kill(src, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	pid = getpid();
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sa.sa_sigaction = signal_handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (ft_putstr_fd("sigaction error\n", 2), 1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (ft_putstr_fd("sigaction error\n", 2), 1);
	while (1)
		pause();
}
