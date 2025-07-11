/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mshaghaf <mshaghaf@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/04 12:14:31 by moshagha      #+#    #+#                 */
/*   Updated: 2025/07/11 17:50:19 by mona          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	char	*str;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}

// int	main(void)
// {
// 	char			string[] = "Hello";
// 	unsigned int	start = 2;
// 	size_t			len = ft_strlen(string);
// 	char			*str;

// 	str = ft_substr(string, start, len);
// 	printf("before freeing: %s\n", str);
// 	free(str);
// 	str = NULL;
// 	printf("after: %s\n", str);
// 	return (0);
// }