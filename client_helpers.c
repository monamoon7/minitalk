/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client_helpers.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mshaghaf <mshaghaf@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/17 14:23:03 by mona          #+#    #+#                 */
/*   Updated: 2025/08/17 14:48:54 by mona          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	is_all_digits(const char *s)
{
	int	i;

	if (!s || !s[0])
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	err(const char *s)
{
	ft_putstr_fd((char *)s, 2);
	return (1);
}
