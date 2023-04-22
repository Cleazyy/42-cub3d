/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:42:58 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/22 12:07:59 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	get_player_spawn_pos(t_data *data)
{
	char	point;
	int		y;
	int		x;

	y = 0;
	while (data->map.array[y])
	{
		x = 0;
		while (data->map.array[y][x])
		{
			if (is_character(data->map.array[y][x]))
			{
				point = data->map.array[y][x];
				data->ply.x = (double) x;
				data->ply.y = (double) y;
			}
			x++;
		}
		y++;
	}
	return (point);
}

static void	get_player_spawn_angle(t_data *data, char point)
{
	if (point == 'N')
	{
		data->ply.angle = M_PI / 2;
		data->ray.dir_x = 0;
		data->ray.dir_y = -1;
	}
	else if (point == 'S')
	{
		data->ply.angle = (3 * M_PI) / 2;
		data->ray.dir_x = 0;
		data->ray.dir_y = 1;
	}
	else if (point == 'W')
	{
		data->ply.angle = M_PI;
		data->ray.dir_x = -1;
		data->ray.dir_y = 0;
	}
	else if (point == 'E')
	{
		data->ply.angle = 0;
		data->ray.dir_x = 1;
		data->ray.dir_y = 0;
	}
}

static void	get_player_camera_plane(t_data *data, char point)
{
	if (point == 'N')
	{
		data->ray.plane_x = 0.66;
		data->ray.plane_y = 0;
	}
	if (point == 'S')
	{
		data->ray.plane_x = -0.66;
		data->ray.plane_y = 0;
	}
	if (point == 'W')
	{
		data->ray.plane_x = 0;
		data->ray.plane_y = 0.66;
	}
	if (point == 'E')
	{
		data->ray.plane_x = 0;
		data->ray.plane_y = -0.66;
	}
}

void	init_player_infos(t_data *data)
{
	char	point;

	point = get_player_spawn_pos(data);
	get_player_spawn_angle(data, point);
	get_player_camera_plane(data, point);
}
