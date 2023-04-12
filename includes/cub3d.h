/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:30:04 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/12 12:35:42 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <mlx.h>
# include "libft.h"
# include "get_next_line.h"
# include "minimap.h"
# include "parsing.h"
# include "msg.h"

# define WIN_W 1280
# define WIN_H 720

# define KEY_UP 13
# define KEY_DOWN 1
# define KEY_LEFT 0
# define KEY_RIGHT 2 
# define KEY_CLOSE 53
# define KEY_A_L 123
# define KEY_A_R 124
# define OFFSET 64

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_len;
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
	t_map		map;
	t_ply		ply;
	t_img		img;
}	t_data;

/* game */
int		init_game(t_data *data);
int		close_window(t_data *data);
int		key_pressed(int key, t_data *data);
/* graphics */
void	display_colors(t_data *data);
void	draw_line(t_data *data, t_ply *player);
void	draw_angle(t_data *data);
/* player */
int		is_character(char c);
/* utils */
void	ft_mlx_pixel_put(t_img *img, int x, int y, int color);
/* utils errors */
int		print_error(char *str);
void	exit_error(char *str);
void	exit_free_error(t_data *data, char *str);
/* utils free */
void	free_array(char **array);
void	free_everythings(t_data *data);

#endif
