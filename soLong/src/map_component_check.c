/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_component_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:52:39 by tyamauch          #+#    #+#             */
/*   Updated: 2023/07/25 21:28:07 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_count(t_component *count)
{
	count->p_count = 0;
	count->e_count = 0;
	count->c_count = 0;
}

static void	add_count(t_component *count, char c)
{
	if (c == 'P')
		count->p_count++;
	else if (c == 'E')
		count->e_count++;
	else if (c == 'C')
		count->c_count++;
}

bool	map_c_check(char **map, int hight, int width)
{
	bool		map_c_flag;
	t_component	count;
	int			i;
	int			j;

	map_c_flag = true;
	init_count(&count);
	i = 0;
	while (i < hight)
	{
		j = 0;
		while (j < width)
		{
			if (map[i][j] == 'C')
				add_count(&count, map[i][j]);
			j++;
		}
		i++;
	}
	if ((count.c_count) != 0)
		map_c_flag = false;
	return (map_c_flag);
}

bool	map_components_check(char **map, int hight, int width)
{
	bool		map_components_flag;
	int			i;
	int			j;
	t_component	count;

	i = 0;
	init_count(&count);
	map_components_flag = true;
	while (i < hight)
	{
		j = 0;
		while (j < width)
		{
			if (map[i][j] == 'P' || map[i][j] == 'E' || map[i][j] == 'C')
				add_count(&count, map[i][j]);
			else if (map[i][j] != '0' && map[i][j] != '1')
				return (map_components_flag = false);
			j++;
		}
		i++;
	}
	if (count.p_count != 1 || count.e_count != 1 || count.c_count == 0)
		map_components_flag = false;
	return (map_components_flag);
}
