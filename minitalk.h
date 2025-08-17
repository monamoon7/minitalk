/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minitalk.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mshaghaf <mshaghaf@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/30 15:00:44 by mona          #+#    #+#                 */
/*   Updated: 2025/08/17 16:13:28 by mona          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include "libft/libft.h"

int			is_all_digits(const char *s);
int			err(const char *s);
int			parse_pid(char *s, pid_t *out);
void		init_masks(sigset_t *block, sigset_t *empty);

#endif