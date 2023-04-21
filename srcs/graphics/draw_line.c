/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 08:43:43 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/04/21 17:35:30 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double	fmodule(float i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}

static int	ft_max(double a, double b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	ft_bresenham_algo(t_data *data, t_ply *player, double x2, double y2)
{
	double	step_x;
	double	step_y;
	double	max;
	double	x;
	double	y;

	x = player->x;
	y = player->y;
	step_x = x2 - x;
	step_y = y2 - y;
	max = ft_max(fmodule(step_x), fmodule(step_y));
	step_x /= max;
	step_y /= max;
	while ((int)(x - x2) || (int)(y - y2))
	{
		if (x >= WIN_W || y >= WIN_H || x <= 0 || y <= 0)
			break ;
		ft_mlx_pixel_put(&data->img, x, y, 0xf6f6f6);
		x += step_x;
		y += step_y;
	}
}

void	draw_line(t_data *data, t_ply *player)
{
	double	alpha;
	int		i;
	double	x;
	double	y;

	alpha = player->angle - M_PI / 6;
	i = 0;
	while (i < data->win_w)
	{
		player->dx = cos(alpha) * 5;
		player->dy = sin(alpha) * 5;
		x = player->x + player->dx * 30;
		y = player->y + player->dy * 30;
		alpha += (((double)1 / (double)data->win_w)) * (M_PI / (double)3);
		ft_bresenham_algo(data, player, x, y);
		i++;
	}
}
