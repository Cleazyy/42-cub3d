/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 08:47:55 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/22 12:55:37 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	update_pos(t_data *data)
{
	double	side_x;
	double	side_y;

	side_x = cos(data->ply.angle + (M_PI / 2)) / 5;
	side_y = sin(data->ply.angle + (M_PI / 2)) / 5;
	if (data->key.w == true)
	{
		data->ply.x -= side_y;
		data->ply.y += side_x;
	}
	if (data->key.a == true)
	{
		data->ply.x += side_x;
		data->ply.y -= side_y;
	}
	if (data->key.s == true)
	{
		data->ply.x += side_y;
		data->ply.y -= side_x;
	}
	if (data->key.d == true)
	{
		data->ply.x -= side_x;
		data->ply.y += side_y;
	}
}

static void	update_angle(t_data *data)
{
	if (data->key.arr_l == true)
	{
		data->ply.angle -= 0.1;
		if (data->ply.angle < 0)
			data->ply.angle += 2 * M_PI;
		if (data->ply.angle > 2 * M_PI)
			data->ply.angle -= 2 * M_PI;
	}
	if (data->key.arr_r == true)
	{
		data->ply.angle += 0.1;
		if (data->ply.angle < 0)
			data->ply.angle += 2 * M_PI;
		if (data->ply.angle > 2 * M_PI)
			data->ply.angle -= 2 * M_PI;
	}
}

void	key_loop(t_data *data)
{
	update_pos(data);
	update_angle(data);
}
