/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 13:14:29 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/22 13:14:58 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

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
	t_img		mat[4];
}	t_data;

#endif
