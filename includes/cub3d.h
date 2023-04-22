/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:30:04 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/22 17:13:28 by fluchten         ###   ########.fr       */
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
# include "game.h"
# include "graphics.h"
# include "language.h"
# include "minimap.h"
# include "parsing.h"
# include "utils.h"

# define WIN_W 1280
# define WIN_H 720
# define MOVE_SPEED 0.09
# define ROT_SPEED 0.09
# define SPRITES_SIZE 64

# define KEY_UP 13
# define KEY_DOWN 1
# define KEY_LEFT 0
# define KEY_RIGHT 2 
# define KEY_CLOSE 53
# define KEY_ARR_L 123
# define KEY_ARR_R 124

typedef enum e_dir
{
	NO = 0,
	SO = 1,
	WE = 2,
	EA = 3,
}	t_dir;

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
	char	*path;
	int		w;
	int		h;
}	t_img;

typedef struct s_map
{
	char		*str;
	char		**array;
	char		*floor_color;
	char		*ceiling_color;
	int			floor_rgb;
	int			ceiling_rgb;
}	t_map;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			win_w;
	int			win_h;
	t_game		game;
	t_key		key;
	t_map		map;
	t_ray		ray;
	t_img		img;
	t_img		mat[4];
}	t_data;

#endif
