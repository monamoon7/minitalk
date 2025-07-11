/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mshaghaf <mshaghaf@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 10:38:46 by moshagha      #+#    #+#                 */
/*   Updated: 2025/07/11 17:47:32 by mona          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *stra, int c, size_t n)
{
	unsigned char	*strb;
	unsigned char	value;

	strb = (unsigned char *)stra;
	value = (unsigned char)c;
	while (n--)
		*strb++ = value;
	return (stra);
}

// int	main(void)
// {
// 	char str[] = "Hello";

// 	printf("Before memset: %s\n", str);

// 	// ft_memset(str, 'a', sizeof(str) - 1);
// 	memset(str, 'a', sizeof(str) - 1);
// 	str[sizeof(str) - 1] = '\0';

// 	printf("After memset: %s\n", str);

// 	return (0);	
// }