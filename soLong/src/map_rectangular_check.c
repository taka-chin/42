/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rectangular_check.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:55:34 by tyamauch          #+#    #+#             */
/*   Updated: 2023/07/20 18:55:43 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	map_rectangular_check(char **map, int hight, int width)
{
	bool	is_rectangular;
	size_t	i;

	is_rectangular = true;
	i = 0;
	while (i < (size_t)hight)
	{
		if (ft_strlen(map[i]) != (size_t)width + 1)
		{
			is_rectangular = false;
			break ;
		}
		i++;
	}
	return (is_rectangular);
}
