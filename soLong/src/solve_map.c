/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 19:00:07 by tyamauch          #+#    #+#             */
/*   Updated: 2023/08/01 21:34:16 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	solve_check(char **map, int hight, int width)
{
	bool	path_flag;
	int		i;
	int		j;

	path_flag = true;
	i = 0;
	while (i < hight)
	{
		j = 0;
		while (j < width)
		{
			if (map[i][j] != 1)
			{
				if (map[i][j] == 'P' || map[i][j] == 'E' || map[i][j] == 'C')
				{
					path_flag = false;
					return (path_flag);
				}
			}
			j++;
		}
		i++;
	}
	return (path_flag);
}

void	recursion(char **map, int x, int y, t_stack *stack)
{
	t_point	*point;

	map[x][y] = '1';
	if (map[x - 1][y] != '1')
		push_stack(stack, x - 1, y);
	if (map[x + 1][y] != '1')
		push_stack(stack, x + 1, y);
	if (map[x][y - 1] != '1')
		push_stack(stack, x, y - 1);
	if (map[x][y + 1] != '1')
		push_stack(stack, x, y + 1);
	if (stack->size != 0)
	{
		point = pop_stack(stack);
		recursion(map, point->x, point->y, stack);
		free(point);
	}
}

void	solve_map(char **map, t_map *scan_value)
{
	t_stack	stack;
	bool	solve_flag;

	solve_flag = true;
	init_stack(&stack);
	recursion(map, scan_value->p_x, scan_value->p_y, &stack);
	solve_flag = solve_check(map, scan_value->hight, scan_value->width);
	if (!solve_flag)
		ft_put_error(MAP_SOLVE_ERROR);
	free_stack(&stack);
}
