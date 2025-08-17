/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mshaghaf <mshaghaf@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/11 16:39:44 by mona          #+#    #+#                 */
/*   Updated: 2025/08/17 12:24:13 by mona          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	flush_byte(unsigned char *ch, int *bit, pid_t pid)
{
	if (*ch == '\0')
	{
		if (pid > 0)
			kill(pid, SIGUSR2); /* end-of-message ack */
	}
	else
		write(1, ch, 1);
	*ch = 0;
	*bit = 0;
}

static void	signal_handler(int sig, siginfo_t *info, void *u)
{
	static unsigned char	ch = 0;
	static int				bit = 0;

	(void)u;
	ch <<= 1;
	if (sig == SIGUSR2)
		ch |= 1;
	bit++;

	/* per-bit ack first, so client unblocks cleanly */
	if (info && info->si_pid > 0)
		kill(info->si_pid, SIGUSR1);

	if (bit == 8)
		flush_byte(&ch, &bit, info ? info->si_pid : 0);
}


int	main(void)
{
	struct	sigaction	sa;
	pid_t				pid;
	
	pid = getpid();
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
	{
    	ft_putstr_fd("sigaction error\n", 2);
    	return (1);
	}
	
	while (1)
		pause();
}