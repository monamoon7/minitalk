/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mshaghaf <mshaghaf@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/06 17:10:31 by moshagha      #+#    #+#                 */
/*   Updated: 2025/07/11 17:50:08 by mona          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isinset(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	new_length;
	char	*str;

	if (!s1)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_isinset(s1[start], set))
		start++;
	if (start != end)
	{
		while (end > start && ft_isinset(s1[end - 1], set))
			end--;
	}
	new_length = end - start;
	str = malloc(new_length + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s1[start], new_length + 1);
	return (str);
}

// int	main(void)
// {
// 	char const	s1[] = "eeHello ByeHHH";
// 	char const	set[] = "eH";
// 	char		*str;

// 	str = ft_strtrim(s1, set);
// 	printf("Before freeing: %s\n", str);
// 	free (str);
// 	str = NULL;
// 	printf("After freeing: %s\n", str);
// 	return (0);
// }
