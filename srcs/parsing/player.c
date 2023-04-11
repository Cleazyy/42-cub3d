/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:42:58 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/11 13:32:57 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	initialize_player_table(t_data *data)
{
	data->ply.x = 0;
	data->ply.y = 0;
	data->ply.angle = 0;
}

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
				data->ply.x = (float) x;
				data->ply.y = (float) y;
			}
			x++;
		}
		y++;
	}
	return (point);
}

static float	get_player_spawn_angle(char point)
{
	float	result;

	if (point == 'N')
		result = M_PI / 2;
	if (point == 'S')
		result = (3 * M_PI) / 2;
	if (point == 'W')
		result = M_PI;
	if (point == 'E')
		result = 0;
	return (result);
}

void	init_player_infos(t_data *data)
{
	char	point;

	initialize_player_table(data);
	point = get_player_spawn_pos(data);
	data->ply.angle = get_player_spawn_angle(point);
}
