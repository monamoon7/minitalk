/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mshaghaf <mshaghaf@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/06 18:55:12 by moshagha      #+#    #+#                 */
/*   Updated: 2025/07/11 17:47:04 by mona          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	length_n(int n)
{
	unsigned int	length;
	int				temp;

	length = 0;
	temp = n;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		length++;
		temp = -temp;
	}
	while (temp != 0)
	{
		length++;
		temp = temp / 10;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	length;
	unsigned int	index;
	long			nbr;

	nbr = n;
	length = length_n(n);
	str = (char *)malloc(sizeof(char) * (length + 1));
	if (!str)
		return (NULL);
	str[length] = '\0';
	index = length - 1;
	if (n == 0)
		str[index] = '0';
	if (n < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		str[index--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}

// int	main(void)
// {
// 	int		n = -89697;
// 	char	*str = ft_itoa(n);

// 	printf("%s\n", str);
// 	free (str);
// 	return (0);
// }