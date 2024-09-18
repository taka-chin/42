/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_wall_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:56:57 by tyamauch          #+#    #+#             */
/*   Updated: 2023/07/20 18:57:06 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	map_wall_check(char **map, int height, int width)
{
	bool	is_wall;
	size_t	i;
	size_t	j;

	is_wall = true;
	i = 0;
	while (i < (size_t)height)
	{
		if (i == 0 || i + 1 == (size_t)height)
		{
			j = 0;
			while (j < (size_t)width)
			{
				if (map[i][j] != '1')
					is_wall = false;
				j++;
			}
		}
		else if (map[i][0] != '1' && map[i][j] != '1')
			is_wall = false;
		i++;
	}
	return (is_wall);
}
