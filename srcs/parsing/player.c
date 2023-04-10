/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:42:58 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/10 16:00:06 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	initialize_player_table(t_data *data)
{
	data->ply.x = 0;
	data->ply.y = 0;
}

static void	set_player_spawn_pos(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map.array[y])
	{
		x = 0;
		while (data->map.array[y][x])
		{
			if (is_character(data->map.array[y][x]))
			{
				data->ply.x = (float) x;
				data->ply.y = (float) y;
			}
			x++;
		}
		y++;
	}
}

void	init_player_infos(t_data *data)
{
	initialize_player_table(data);
	set_player_spawn_pos(data);
}
