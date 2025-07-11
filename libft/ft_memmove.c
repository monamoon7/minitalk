/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mshaghaf <mshaghaf@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/30 15:47:37 by moshagha      #+#    #+#                 */
/*   Updated: 2025/07/11 17:47:27 by mona          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*dest_bigger(unsigned char *dest, const unsigned char *src, size_t n)
{
	if (dest > src)
	{
		dest += n - 1;
		src += n - 1;
		while (n > 0)
		{
			*dest = *src;
			dest--;
			src--;
			n--;
		}
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*destb;
	const unsigned char	*srcb;

	destb = (unsigned char *)dest;
	srcb = (const unsigned char *)src;
	if (dest > src)
		dest_bigger(destb, srcb, n);
	else
		ft_memcpy(destb, srcb, n);
	return (dest);
}

// int	main(void)
// {
// 	unsigned char dest[] = "Wasserreiniger";
// 	const char src[] = "Regenbogen";
// 	size_t i = 2;

// 	char *temp = (char *)ft_memmove(dest, src, i);

// 	printf("%s\n", temp);
// 	return (0);
// }