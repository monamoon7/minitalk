/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mshaghaf <mshaghaf@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 12:40:39 by moshagha      #+#    #+#                 */
/*   Updated: 2025/07/11 17:50:32 by mona          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int i)
{
	if (i >= 'a' && i <= 'z')
		i = i - 32;
	return (i);
}

// int	main(void)
// {
// 	char ch = 'h';
// 	char result = ft_toupper(ch);
// 	printf("uppercase of %c is %c\n", ch, result);

// 	return (0);
// }