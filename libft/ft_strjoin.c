/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mshaghaf <mshaghaf@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/04 15:53:42 by moshagha      #+#    #+#                 */
/*   Updated: 2025/07/11 17:48:30 by mona          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

// int	main(void)
// {
// 	char const	s1[] = "Hello ";
// 	char const	s2[] = "Bye";
// 	char		*str;

// 	str = ft_strjoin(s1, s2);
// 	printf("before %s\n", str);
// 	free(str);
// 	str = NULL;
// 	printf("after freeing:%s\n", str);
// 	return (0);
// }
