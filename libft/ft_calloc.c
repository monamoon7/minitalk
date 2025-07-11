/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mshaghaf <mshaghaf@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/30 15:58:56 by moshagha      #+#    #+#                 */
/*   Updated: 2025/07/11 17:46:31 by mona          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	mem = malloc(count * size);
	if (mem == NULL)
		return (NULL);
	ft_bzero(mem, count * size);
	return (mem);
}

// int	main(void)
// {
// 	int	*arr;

// 	arr = (int *)ft_calloc(3, sizeof(int));
// 	if (!arr)
// 	{
// 		printf("Failed Memory Allocation\n");
// 		return (1);
// 	}
// 	if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0)
// 		printf("Memory zero-initialized!\n");
// 	else
// 		printf("Memory not zero-initialized!\n");
// 	free(arr);
// 	return (0);
// }
