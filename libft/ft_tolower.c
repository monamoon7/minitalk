/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mshaghaf <mshaghaf@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 15:45:02 by moshagha      #+#    #+#                 */
/*   Updated: 2025/07/11 17:50:27 by mona          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int i)
{
	if (i >= 'A' && i <= 'Z')
		i = i + 32;
	return (i);
}

// int	main(void)
// {
// 	char	c = 'H';
// 	char	result = ft_tolower(c);
// 	printf("before tolower %c, after: %c\n", c, result);
// 	return (0);
// }