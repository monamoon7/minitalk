/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mshaghaf <mshaghaf@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/11 16:39:44 by mona          #+#    #+#                 */
/*   Updated: 2025/07/13 16:39:05 by mona          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "libft.h"

void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
		write(1, "0", 1);
	else if (signal == SIGUSR2)
		write(1, "1", 1);
}

int	main(void)
{
	struct	sigaction	sa;
	pid_t				pid;
	
	pid = getpid();
	write(1, "Server PID: ", 13);
	ft_putnbr_fd()
}