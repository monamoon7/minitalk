/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mshaghaf <mshaghaf@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/11 16:39:44 by mona          #+#    #+#                 */
/*   Updated: 2025/07/30 14:49:22 by mona          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "libft/libft.h"

void	signal_handler(int signal)
{
	static unsigned char	character = 0;
	static int				bit_count = 0;

	character <<= 1; //shift left by 1 so we can make spcae for a new bit

	if (signal == SIGUSR2)
		character |= 1; // if bit is a 1, set the last bit to 1

	bit_count++;

	if (bit_count == 8)
	{
		write(1, &character, 1);
		character = 0;
		bit_count = 0;
	}

}

int	main(void)
{
	struct	sigaction	sa;
	pid_t				pid;
	
	pid = getpid();
	write(1, "Server PID: ", 13);
	ft_putnbr_fd(pid, 1);
	write (1, "\n", 1);

	sa.sa_handler = &signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	
	while (1)
		pause();
}