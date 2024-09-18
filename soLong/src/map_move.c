/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 19:24:58 by tyamauch          #+#    #+#             */
/*   Updated: 2023/08/01 20:53:14 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_point	make_num_tmp(int key_code, int x, int y)
{
	t_point	num_tmp;

	num_tmp.x = x;
	num_tmp.y = y;
	if (key_code == KEY_W)
		num_tmp.x = x - 1;
	else if (key_code == KEY_S)
		num_tmp.x = x + 1;
	else if (key_code == KEY_A)
		num_tmp.y = y - 1;
	else if (key_code == KEY_D)
		num_tmp.y = y + 1;
	return (num_tmp);
}

char	make_tmp_char(t_mlx_data *data, t_point num_tmp, int *x, int *y)
{
	char	tmp;

	tmp = data->map[*x][*y];
	if (data->map[*x][*y] == 'Z')
	{
		tmp = 'P';
		data->map[num_tmp.x][num_tmp.y] = 'E';
	}
	else if (data->map[num_tmp.x][num_tmp.y] == 'C')
		data->map[num_tmp.x][num_tmp.y] = '0';
	else if (data->map[num_tmp.x][num_tmp.y] == 'E')
	{
		if (map_c_check(data->map, data->map_data->hight,
				data->map_data->width))
			exit(0);
		else
		{
			tmp = 'Z';
			data->map[num_tmp.x][num_tmp.y] = '0';
		}
	}
	return (tmp);
}

void	swap_check(int key_code, t_mlx_data *data, int *x, int *y)
{
	t_point	num_tmp;
	char	tmp;

	num_tmp = make_num_tmp(key_code, *x, *y);
	tmp = make_tmp_char(data, num_tmp, x, y);
	data->map[*x][*y] = data->map[num_tmp.x][num_tmp.y];
	data->map[num_tmp.x][num_tmp.y] = tmp;
	*x = num_tmp.x;
	*y = num_tmp.y;
}

bool	map_swap(int key_code, t_mlx_data *data)
{
	bool	swap_flag;
	int		*x;
	int		*y;
	t_point	num_tmp;

	swap_flag = true;
	x = &data->map_data->p_x;
	y = &data->map_data->p_y;
	num_tmp = make_num_tmp(key_code, *x, *y);
	if (data->map[num_tmp.x][num_tmp.y] == '1')
	{
		swap_flag = false;
		return (swap_flag);
	}
	swap_check(key_code, data, x, y);
	ft_mlx_put_image(data, NULL, data->map_data);
	return (swap_flag);
}
