/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_rules.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <tyamauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 22:39:41 by tyamauch          #+#    #+#             */
/*   Updated: 2023/05/31 22:42:25 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	swap(int *a, int *b)
{
	size_t	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

size_t	bubble_sort(int *num, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	count = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (num[i] >= num[j])
			{
				swap(&num[i], &num[j]);
				count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}
