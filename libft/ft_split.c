/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mshaghaf <mshaghaf@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/06 18:57:48 by moshagha      #+#    #+#                 */
/*   Updated: 2025/07/11 17:48:09 by mona          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(const char *str, char c)
{
	int	count;
	int	location;

	count = 0;
	location = 0;
	while (*str)
	{
		if (*str != c && location == 0)
		{
			location = 1;
			count++;
		}
		else if (*str == c)
			location = 0;
		str++;
	}
	return (count);
}

int	next_word(const char *s, char c, int *i)
{
	int	start;

	while (s[*i] == c)
		(*i)++;
	start = *i;
	while (s[*i] && s[*i] != c)
		(*i)++;
	return (start);
}

char	*malloc_word(const char *s, int start, int end)
{
	int		length;
	int		i;
	char	*str;

	length = end - start;
	str = (char *)malloc(sizeof(char) * (length + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < length)
	{
		str[i] = s[start + i];
		i++;
	}
	str[length] = '\0';
	return (str);
}

void	*free_split(char **str, int allocated)
{
	int	i;

	i = 0;
	while (i < allocated)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		start;
	int		word_count;
	int		word_location;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	str = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!str)
		return (NULL);
	i = 0;
	word_location = 0;
	while (s[i] && word_location < word_count)
	{
		start = next_word(s, c, &i);
		str[word_location] = malloc_word(s, start, i);
		if (!str[word_location])
			return (free_split(str, word_location));
		word_location++;
	}
	str[word_count] = NULL;
	return (str);
}

// int	main(void)
// {
// 	const char	str[] = "Banane Apfel Birne";
// 	char		c = ' ';
// 	char		**words = ft_split(str, c);
// 	int			i;

// 	if (words == NULL)
// 		return (1);
// 	i = 0;
// 	while (words[i] != NULL)
// 	{
// 		printf("%s\n", words[i]);
// 		i++;
// 	}	
// 	free_split(words, count_words(str, c));
// 	return (0);
// }
