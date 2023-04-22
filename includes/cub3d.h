/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:30:04 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/22 11:53:45 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <math.h>
# include <mlx.h>

# include "libft.h"
# include "get_next_line.h"
# include "minimap.h"
# include "parsing.h"
# include "graphics.h"

# define WIN_W 1280
# define WIN_H 720

# define KEY_UP 13
# define KEY_DOWN 1
# define KEY_LEFT 0
# define KEY_RIGHT 2 
# define KEY_CLOSE 53
# define KEY_ARR_L 123
# define KEY_ARR_R 124
# define OFFSET 64

# define MSG_ERROR "\033[1;31mError\033[0m"
# define MSG_MALLOC_ERR "malloc() failed!"
# define MSG_MLX_FAILED "Mlx initialization failed!"

typedef struct s_key
{
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	arr_l;
	bool	arr_r;
}	t_key;

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_sprite
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
}	t_sprite;

typedef struct s_ply
{
	double	x;
	double	y;
	double	dx;
	double	dy;
	double	angle;
}	t_ply;

typedef struct s_map
{
	char		*str;
	char		**array;
	char		*floor_color;
	char		*ceiling_color;
	int			floor_rgb;
	int			ceiling_rgb;
	t_sprite	sprite;
}	t_map;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			win_w;
	int			win_h;
	t_key		key;
	t_map		map;
	t_ply		ply;
	t_ray		ray;
	t_img		img;
}	t_data;

/* game */
int		init_game(t_data *data);
int		close_window(t_data *data);
int		key_pressed(int key, t_data *data);
int		key_release(int key, t_data *data);
void	key_loop(t_data *data);
/* utils */
int		is_character(char c);
/* utils errors */
int		print_error(char *str);
void	exit_error(char *str);
void	exit_free_error(t_data *data, char *str);
/* utils free */
void	free_array(char **array);
void	free_everythings(t_data *data);

#endif
