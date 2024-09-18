/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 19:25:27 by tyamauch          #+#    #+#             */
/*   Updated: 2023/08/01 18:46:10 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	scan_map(char *path, t_map *scan_value)
{
	int		count;
	int		len;
	char	*buf;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_put_error(FILE_NOT_FOUND);
	count = 0;
	len = 0;
	while (1)
	{
		buf = get_next_line(fd);
		if (buf == NULL)
			break ;
		if (count == 0)
			len = ft_strlen(buf);
		free(buf);
		count++;
	}
	if (count > MAP_MAX_SIZE_HIGH || len - 1 > MAP_MAX_SIZE_WIDTH)
		ft_put_error(MAP_SIZE_ERROR);
	scan_value->hight = count;
	scan_value->width = len - 1;
	close(fd);
}

char	**create_map(char *path, t_map *scan_value)
{
	char	**map;
	int		i;
	int		row;
	int		col;
	int		fd;

	row = scan_value->hight;
	col = scan_value->width;
	fd = open(path, O_RDONLY);
	map = (char **)malloc(sizeof(char *) * row);
	if (map == NULL)
		exit(1);
	i = 0;
	while (i < row)
	{
		map[i] = get_next_line(fd);
		if (map[i] == NULL)
			exit(1);
		i++;
	}
	close(fd);
	return (map);
}

void	scan_map_start(char **map, t_map *scan_value)
{
	int	i;
	int	j;

	i = 0;
	while (i < scan_value->hight)
	{
		j = 0;
		while (j < scan_value->width)
		{
			if (map[i][j] == 'P')
			{
				scan_value->p_x = i;
				scan_value->p_y = j;
			}
			j++;
		}
		i++;
	}
}

char	**free_map(char **s, int hight)
{
	int	i;

	i = 0;
	while (i < hight)
		free(s[i++]);
	free(s);
	return (NULL);
}
