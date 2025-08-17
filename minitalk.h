/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minitalk.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mshaghaf <mshaghaf@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/30 15:00:44 by mona          #+#    #+#                 */
/*   Updated: 2025/08/17 11:19:53 by mona          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include "libft/libft.h"

/* Protocol mapping: SIGUSR1 = 0, SIGUSR2 = 1, MSB first */

/* client.c */
void	send_char(pid_t pid, unsigned char c);

#endif