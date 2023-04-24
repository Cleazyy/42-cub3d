/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_crosshair.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 10:48:46 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/24 11:25:15 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* initialize_crosshair_table initializes the variables of the crosshair
structure and check if its size is not bigger than the window */
static int	initialize_crosshair_table(t_data *data, t_cross *cross)
{
	cross->size = 10;
	if (cross->size * 2 > data->win_w || cross->size * 2 > data->win_h)
		return (1);
	cross->cx = data->win_w / 2;
	cross->cy = data->win_h / 2;
	cross->clr = 0xafb3ae;
	return (0);
}

/* draw_crosshair draws a vertical and a horizontal line
in the middle of the window */
static void	draw_crosshair(t_data *data, t_cross *cross)
{
	int	x;
	int	y;

	y = -cross->size;
	while (y < cross->size)
	{
		ft_mlx_pixel_put(&data->img, cross->cx - 1, cross->cy + y, cross->clr);
		ft_mlx_pixel_put(&data->img, cross->cx, cross->cy + y, cross->clr);
		ft_mlx_pixel_put(&data->img, cross->cx + 1, cross->cy + y, cross->clr);
		y++;
	}
	x = -cross->size;
	while (x < cross->size)
	{	
		ft_mlx_pixel_put(&data->img, cross->cx + x, cross->cy - 1, cross->clr);
		ft_mlx_pixel_put(&data->img, cross->cx + x, cross->cy, cross->clr);
		ft_mlx_pixel_put(&data->img, cross->cx + x, cross->cy + 1, cross->clr);
		x++;
	}
}

/* init_crosshair draws initializes the crosshair */
void	init_crosshair(t_data *data)
{
	if (initialize_crosshair_table(data, &data->cross) != 0)
		return ;
	draw_crosshair(data, &data->cross);
}
