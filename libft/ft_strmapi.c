/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mshaghaf <mshaghaf@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/06 17:39:25 by moshagha      #+#    #+#                 */
/*   Updated: 2025/07/11 17:48:58 by mona          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (!s || !f)
		return (NULL);
	str = (char *)malloc(ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

// char	index_char(unsigned int i, char c)
// {
// 	printf("Index: %u, Char: %c\n", i, c);
// 	return (c);
// }

// int	main(void)
// {
// 	char	s[] = "Hello";
// 	char	*str;

// 	str = ft_strmapi(s, index_char);
// 	free (str);
// 	return (0);
// }
