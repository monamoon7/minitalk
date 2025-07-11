/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mshaghaf <mshaghaf@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 17:54:38 by moshagha      #+#    #+#                 */
/*   Updated: 2025/07/11 17:48:36 by mona          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	src_len;
	size_t	dest_len;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	i = dest_len;
	j = 0;
	if (size < dest_len + 1)
		return (size + src_len);
	if (size > dest_len + 1)
	{
		while (i + j < size - 1 && src[j] != '\0')
		{
			dest[i + j] = src[j];
			j++;
		}
	}
	dest[i + j] = '\0';
	return (dest_len + src_len);
}

// int	main(void)
// {
// 	char dest[5];
// 	char src[] = "Wa";

// 	printf("%zu\n", ft_strlcat(dest, src, sizeof(dest)));
// 	return (0);
// }