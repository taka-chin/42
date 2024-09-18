/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:39:13 by tyamauch          #+#    #+#             */
/*   Updated: 2023/08/01 21:43:37 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "get_next_line.h"
# include <fcntl.h>
# include <limits.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>

# define PATH_1 "../img/Assets.xpm"
# define PATH_P "../img/mini_capy3.xpm"
# define PATH_0 "../img/Tiles.xpm"
# define PATH_D_OPEN "../img/Tiles4.xpm"
# define PATH_D_CLOSE "../img/Tiles3.xpm"
# define PATH_C "../img/Tiles1.xpm"
# define PATH_Z "../img/PandDoor.xpm"
# define P_SIZE 100
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define MAP_MAX_SIZE_HIGH 14
# define MAP_MAX_SIZE_WIDTH 26

enum				e_error_type
{
	ARGS_ERROR,
	FILE_NOT_FOUND,	
	MAP_SIZE_ERROR,
	MAP_WALL_ERROR,
	RECTANGULAR_ERROR,
	SURROUNDED_ERROR,
	MAP_COMPONENTS_ERROR,
	MAP_SOLVE_ERROR,
	FILE_NAME_ERROR	
};

typedef struct s_point
{
	int				x;
	int				y;
	struct s_point	*prev;
}					t_point;

typedef struct s_map
{
	int				hight;
	int				width;
	int				p_y;
	int				p_x;
}					t_map;

typedef struct s_component
{
	int				p_count;
	int				e_count;
	int				c_count;
}					t_component;

typedef struct s_stack
{
	int				size;
	t_point			*point;
}					t_stack;

typedef struct s_mlx_data
{
	void			*mlx;
	void			*mlx_win;
	char			**map;
	char			*path;
	t_map			*map_data;
}					t_mlx_data;

void				ft_put_error(int e_error_type);
bool				map_wall_check(char **map, int heignt, int width);
bool				map_rectangular_check(char **map, int hight, int width);
bool				map_components_check(char **map, int hight, int width);
bool				map_c_check(char **map, int hight, int width);
void				error_check(char **map, int hight, int width);
void				scan_map(char *path, t_map *scan_value);
char				**create_map(char *path, t_map *scan_value);
void				solve_map(char **map, t_map *scan_value);
void				init_stack(t_stack *stack);
void				push_stack(t_stack *stack, int i, int j);
t_point				*pop_stack(t_stack *stack);
void free_stack(t_stack *stack);
void				mlx(t_mlx_data *data, t_map *scan_value);
void				scan_map_start(char **map, t_map *scan_value);
char				**free_map(char **s, int hight);
void				ft_putchar_fd(char c, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_put_error(int e_error_type);
bool				map_swap(int key_code, t_mlx_data *data);
void				ft_mlx_put_image(t_mlx_data *data, void *img,
						t_map *scan_value);
bool key_code_check(int key_code);

#endif
