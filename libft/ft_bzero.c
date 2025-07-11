/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mshaghaf <mshaghaf@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 12:37:44 by moshagha      #+#    #+#                 */
/*   Updated: 2025/07/11 17:46:27 by mona          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n--)
		*p++ = 0;
}

// int	main(void)
// {
// 	int		i;
// 	char	arr[3] = {'W', 'Q', 'A'};

// 	i = 0;
// 	ft_bzero(arr, 3);
// 	while(i < 3)
// 	{
// 		printf("%d\n", arr[i]);
// 		i++;
// 	}
// 	return (0);
// }