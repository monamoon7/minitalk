/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mshaghaf <mshaghaf@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/04 11:23:06 by moshagha      #+#    #+#                 */
/*   Updated: 2025/07/11 17:48:04 by mona          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
}

// int	main(void)
// {
// 	char	s[] = "wasser";
// 	ft_putstr_fd(s, 1);
// 	return (0);
// }