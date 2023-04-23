/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:42:13 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/23 16:48:10 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* draw_background draws the top and bottom of the window with the
ceiling and sky colors */
void	draw_background(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < (data->win_h / 2))
	{
		x = 0;
		while (x < data->win_w)
		{
			ft_mlx_pixel_put(&data->img, x, y,
				data->map.ceiling_rgb);
			ft_mlx_pixel_put(&data->img, x, y + (data->win_h / 2),
				data->map.floor_rgb);
			x++;
		}
		y++;
	}
}
