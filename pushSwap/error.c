/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <tyamauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 19:57:25 by tyamauch          #+#    #+#             */
/*   Updated: 2023/06/14 19:57:36 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_put_error(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(1);
}

void	duplicated_check(unsigned int *num_compress, size_t array_length)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < array_length)
	{
		j = i + 1;
		while (j < array_length)
		{
			if (num_compress[i] == num_compress[j])
				ft_put_error();
			j++;
		}
		i++;
	}
}
