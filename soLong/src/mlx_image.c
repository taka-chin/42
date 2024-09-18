/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 19:22:20 by tyamauch          #+#    #+#             */
/*   Updated: 2023/08/01 21:03:25 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*make_image(t_mlx_data *data, void *img, int i, int j)
{
	int	img_width;
	int	img_hight;

	if (data->map[i][j] == 'P')
		img = mlx_xpm_file_to_image(data->mlx, PATH_P, &img_width, &img_hight);
	else if (data->map[i][j] == '1')
		img = mlx_xpm_file_to_image(data->mlx, PATH_1, &img_width, &img_hight);
	else if (data->map[i][j] == '0')
		img = mlx_xpm_file_to_image(data->mlx, PATH_0, &img_width, &img_hight);
	else if (data->map[i][j] == 'E')
	{
		if (map_c_check(data->map, data->map_data->hight,
				data->map_data->width))
			img = mlx_xpm_file_to_image(data->mlx, PATH_D_OPEN, &img_width,
					&img_hight);
		else
			img = mlx_xpm_file_to_image(data->mlx, PATH_D_CLOSE, &img_width,
					&img_hight);
	}
	else if (data->map[i][j] == 'Z')
		img = mlx_xpm_file_to_image(data->mlx, PATH_Z, &img_width, &img_hight);
	else
		img = mlx_xpm_file_to_image(data->mlx, PATH_C, &img_width, &img_hight);
	return (img);
}

void	ft_mlx_put_image(t_mlx_data *data, void *img, t_map *scan_value)
{
	int	i;
	int	j;

	j = 0;
	while (j < scan_value->width)
	{
		i = 0;
		while (i < scan_value->hight)
		{
			img = make_image(data, img, i, j);
			mlx_put_image_to_window(data->mlx, data->mlx_win, img, P_SIZE * j,
				P_SIZE * i);
			mlx_destroy_image(data->mlx, img);
			i++;
		}
		j++;
	}
}

int	ft_key_hook(int key_code, t_mlx_data *data)
{
	static int	step_num;

	if (key_code == KEY_ESC)
		exit(0);
	else
	{
		if(key_code_check(key_code))
		{
			if (map_swap(key_code, data))
			{
				ft_putnbr_fd(++step_num, 1);
				ft_putchar_fd('\n', 1);
			}
		}
	}
	return (1);
}

int	ft_window_close(t_mlx_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	free_map(data->map, data->map_data->hight);
	exit(0);
}

void	mlx(t_mlx_data *data, t_map *scan_value)
{
	void	*img;

	data->mlx = mlx_init();
	img = NULL;
	data->mlx_win = mlx_new_window(data->mlx, P_SIZE * (scan_value->width),
			P_SIZE * (scan_value->hight), "Play GAME!");
	data->map_data = scan_value;
	ft_mlx_put_image(data, img, scan_value);
	mlx_key_hook(data->mlx_win, ft_key_hook, data);
	mlx_hook(data->mlx_win, 17, 1L << 2, ft_window_close, data);
	mlx_loop(data->mlx);
}
