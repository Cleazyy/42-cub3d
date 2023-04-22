/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:42:58 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/22 20:19:50 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	get_player_spawn_pos(t_data *data)
{
	char	dir;
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
				dir = data->map.array[y][x];
				data->ray.x = (double) x;
				data->ray.y = (double) y;
			}
			x++;
		}
		y++;
	}
	return (dir);
}

static void	get_player_spawn_dir(t_data *data, char dir)
{
	if (dir == 'N')
	{
		data->ray.dir_x = 0;
		data->ray.dir_y = -1;
	}
	else if (dir == 'S')
	{
		data->ray.dir_x = 0;
		data->ray.dir_y = 1;
	}
	else if (dir == 'W')
	{
		data->ray.dir_x = -1;
		data->ray.dir_y = 0;
	}
	else if (dir == 'E')
	{
		data->ray.dir_x = 1;
		data->ray.dir_y = 0;
	}
}

static void	get_player_camera_plane(t_data *data, char dir)
{
	if (dir == 'N')
	{
		data->ray.plane_x = data->game.fov;
		data->ray.plane_y = 0;
	}
	if (dir == 'S')
	{
		data->ray.plane_x = -data->game.fov;
		data->ray.plane_y = 0;
	}
	if (dir == 'W')
	{
		data->ray.plane_x = 0;
		data->ray.plane_y = data->game.fov;
	}
	if (dir == 'E')
	{
		data->ray.plane_x = 0;
		data->ray.plane_y = -data->game.fov;
	}
}

void	init_player_infos(t_data *data)
{
	data->map.dir = get_player_spawn_pos(data);
	get_player_spawn_dir(data, data->map.dir);
	get_player_camera_plane(data, data->map.dir);
}
