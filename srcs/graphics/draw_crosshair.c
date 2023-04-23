/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_crosshair.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 10:48:46 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/23 10:49:01 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_crosshair(t_data *data)
{
	int	center_x;
	int	center_y;
	int	size;
	int	x;
	int	y;

	center_x = data->win_w / 2;
	center_y = data->win_h / 2;
	size = 10;
	y = -size;
	while (y < size)
	{
		ft_mlx_pixel_put(&data->img, center_x - 1, center_y + y, 0xafb3ae);
		ft_mlx_pixel_put(&data->img, center_x, center_y + y, 0xafb3ae);
		ft_mlx_pixel_put(&data->img, center_x + 1, center_y + y, 0xafb3ae);
		y++;
	}
	x = -size;
	while (x < size)
	{	
		ft_mlx_pixel_put(&data->img, center_x + x, center_y - 1, 0xafb3ae);
		ft_mlx_pixel_put(&data->img, center_x + x, center_y, 0xafb3ae);
		ft_mlx_pixel_put(&data->img, center_x + x, center_y + 1, 0xafb3ae);
		x++;
	}
}
