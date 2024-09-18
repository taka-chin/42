/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_compress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <tyamauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:15:34 by tyamauch          #+#    #+#             */
/*   Updated: 2023/06/14 20:15:36 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

unsigned int	*make_compress(int *num, int *sorted_num, size_t array_length)
{
	unsigned int	*num_compress;
	size_t			i;
	size_t			j;

	num_compress = (unsigned int *)malloc(sizeof(unsigned int) * array_length);
	i = 0;
	while (i < array_length)
	{
		j = 0;
		while (j < array_length)
		{
			if (num[i] == sorted_num[j])
				num_compress[i] = j;
			j++;
		}
		i++;
	}
	return (num_compress);
}
