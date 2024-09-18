/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <tyamauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 07:23:24 by tyamauch          #+#    #+#             */
/*   Updated: 2023/08/01 21:43:37 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

 __attribute__((destructor)) void destructor(void) { system("leaks so_long"); } 

static bool	file_check(const char *file_name)
{
	size_t	i;

	i = 0;
	while (file_name[i] != '\0')
		i++;
	if (i < 5)
		return (false);
	if (file_name[i - 4] != '.')
		return (false);
	if (file_name[i - 3] != 'b')
		return (false);
	if (file_name[i - 2] != 'e')
		return (false);
	if (file_name[i - 1] != 'r')
		return (false);
	return (true);
}

bool key_code_check(int key_code)
{
	if(key_code == KEY_W)
		return (true);
	if(key_code == KEY_A)
		return (true);
	if(key_code == KEY_S)
		return (true);
	if(key_code == KEY_D)
		return (true);
	else
		return (false);
}

int	main(int argc, char *argv[])
{
	t_mlx_data	data;
	t_map		scan_value;

	if (argc != 2)
		ft_put_error(ARGS_ERROR);
	if (!file_check(argv[1]))
		ft_put_error(FILE_NAME_ERROR);
	data.path = ft_strjoin("../map/", argv[1]);
	scan_map(data.path, &scan_value);
	data.map = create_map(data.path, &scan_value);
	error_check(data.map, scan_value.hight, scan_value.width);
	scan_map_start(data.map, &scan_value);
	solve_map(data.map, &scan_value);
	free_map(data.map, scan_value.hight);
	data.map = create_map(data.path, &scan_value);
	mlx(&data, &scan_value);
	free(data.path);
	return (0);
}
