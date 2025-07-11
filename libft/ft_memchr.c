/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mshaghaf <mshaghaf@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/11 15:31:59 by mona          #+#    #+#                 */
/*   Updated: 2025/07/11 17:47:10 by mona          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr = (const unsigned char *)s;
	const unsigned char	ch = (unsigned char)c;

	while (n--)
	{
		if (*ptr == ch)
			return ((void *)ptr);
		ptr++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	str[] = "Hello World!";
// 	char	*ptr = ft_memchr(str, 'W', 8);
// 	printf("%s\n", ptr);
// 	return (0);
// }