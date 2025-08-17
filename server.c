/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mshaghaf <mshaghaf@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/11 16:39:44 by mona          #+#    #+#                 */
/*   Updated: 2025/08/17 12:00:36 by mona          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	signal_handler(int signal, siginfo_t *info, void *ucontext)
{
	static unsigned char	character = 0;
	static int				bit_count = 0;

	(void)ucontext;

	character <<= 1; /* make room for the new bit */
	if (signal == SIGUSR2)
		character |= 1; /* incoming bit is 1 */

	bit_count++;
	if (bit_count == 8)
	{
		write(1, &character, 1);
		character = 0;
		bit_count = 0;
	}

	/* ACK: tell the client we're ready for the next bit */
	if (info && info->si_pid > 0)
		kill(info->si_pid, SIGUSR1);
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