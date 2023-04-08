/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:26:19 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/08 14:44:19 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_background(t_data *data, int x_pos, int y_pos)
{
	int	x;
	int	y;

	y = 0;
	while (y < MINI_H)
	{
		x = 0;
		while (x < MINI_W)
		{
			ft_mlx_pixel_put(&data->img, x + x_pos, y + y_pos, 0x1e202a);
			ft_mlx_pixel_put(&data->img, x + x_pos, y_pos, 0x53595d);
			ft_mlx_pixel_put(&data->img, x + x_pos, y_pos + MINI_H, 0x53595d);
			ft_mlx_pixel_put(&data->img, x_pos, y + y_pos, 0x53595d);
			ft_mlx_pixel_put(&data->img, x_pos + MINI_W, y + y_pos, 0x53595d);
			x++;
		}
		y++;
	}
}

void	init_minimap(t_data *data)
{
	draw_background(data, 10, 10);
}
