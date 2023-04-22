/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 10:42:17 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/22 20:36:01 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	initialize_game_table(t_data *data)
{
	data->game.w = WIN_W;
	data->game.h = WIN_H;
	data->game.mat_px = MAT_PX;
	data->game.fov = FOV;
	data->game.move_speed = MOVE_SPEED;
	data->game.rot_speed = ROT_SPEED;
}

static void	initialize_map_table(t_data *data)
{
	int	i;

	data->map.str = NULL;
	data->map.array = NULL;
	data->img.ptr = NULL;
	i = 0;
	while (i < 4)
	{
		data->mat[i].ptr = NULL;
		data->mat[i].path = NULL;
		i++;
	}
	data->map.floor_color = NULL;
	data->map.ceiling_color = NULL;
	data->map.floor_rgb = 0;
	data->map.ceiling_rgb = 0;
	data->map.dir = 0;
}

static void	initialize_player_table(t_data *data)
{
	data->ray.x = 0;
	data->ray.y = 0;
}

static void	initialize_key_table(t_data *data)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		data->key[i] = false;
		i++;
	}
}

void	parsing_tables_initialization(t_data *data)
{
	data->win_w = WIN_W;
	data->win_h = WIN_H;
	initialize_game_table(data);
	initialize_map_table(data);
	initialize_player_table(data);
	initialize_key_table(data);
	initialize_ray_table(&data->ray);
}
