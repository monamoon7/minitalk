/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minitalk.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mshaghaf <mshaghaf@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/30 15:00:44 by mona          #+#    #+#                 */
/*   Updated: 2025/08/17 18:05:18 by mona          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include "libft/libft.h"

extern volatile sig_atomic_t	g_got_ack;
extern volatile sig_atomic_t	g_eom;

int		is_all_digits(const char *s);
int		err(const char *s);
int		parse_pid(char *s, pid_t *out);
void	init_masks(sigset_t *block, sigset_t *empty);
int		wait_for_ack(const sigset_t *empty);
int		send_bit(pid_t pid, int bit, const sigset_t *empty);
int		send_char(pid_t pid, unsigned char c, const sigset_t *empty);
int		send_str(pid_t pid, const unsigned char *p, const sigset_t *empty);

#endif