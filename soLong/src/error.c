/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:52:00 by tyamauch          #+#    #+#             */
/*   Updated: 2023/08/01 18:41:07 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_check(char **map, int hight, int width)
{
	if (!map_components_check(map, hight, width))
	{
		free_map(map, hight);
		ft_put_error(MAP_COMPONENTS_ERROR);
	}
	else if (!map_rectangular_check(map, hight, width))
	{
		free_map(map, hight);
		ft_put_error(RECTANGULAR_ERROR);
	}
	else if (!map_wall_check(map, hight, width))
	{
		free_map(map, hight);
		ft_put_error(MAP_WALL_ERROR);
	}
}

void	ft_put_error(int e_error_type)
{
	ft_putstr_fd("Error\n", 1);
	if (e_error_type == ARGS_ERROR)
		ft_putstr_fd("args is not correct\n", 1);
	else if (e_error_type == FILE_NOT_FOUND)
		ft_putstr_fd("file is not found\n", 1);
	else if (e_error_type == MAP_SIZE_ERROR)
		ft_putstr_fd("map is too large\n", 1);
	else if (e_error_type == FILE_NAME_ERROR)
		ft_putstr_fd("file is not correct\n", 1);
	else if (e_error_type == MAP_COMPONENTS_ERROR)
		ft_putstr_fd("map component is not correct\n", 1);
	else if (e_error_type == RECTANGULAR_ERROR)
		ft_putstr_fd("map is not rectangular\n", 1);
	else if (e_error_type == MAP_WALL_ERROR)
		ft_putstr_fd("map is not surrounded wall\n", 1);
	else if (e_error_type == MAP_SOLVE_ERROR)
		ft_putstr_fd("map is not solve\n", 1);
	exit(1);
}
