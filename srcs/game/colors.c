/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:44:39 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/11 21:20:39 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	display_colors(t_data *data)
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
			ft_mlx_pixel_put(&data->img, x, y + (WIN_H / 2),
				data->map.floor_rgb);
			x++;
		}
		y++;
	}
}
