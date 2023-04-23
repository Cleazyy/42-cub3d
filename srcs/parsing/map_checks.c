/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 08:26:30 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/23 16:00:00 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* only_valid_items checks if the map contains only valid items */
static int	only_valid_items(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '0' && map[y][x] != '1' && map[y][x] != ' '
				&& !is_character(map[y][x]))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

/* count_spawn_pos checks if there is only 1 position of player's spawn */
static int	count_spawn_pos(char **map)
{
	int	count;
	int	y;
	int	x;

	y = 0;
	count = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (is_character(map[y][x]))
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

/* check_is_valid_map checksif the map is valid */
void	check_is_valid_map(t_data *data)
{
	if (only_valid_items(data->map.array) != 0)
		exit_free_error(data, MSG_INVALID_ITEMS);
	if (count_spawn_pos(data->map.array) != 1)
		exit_free_error(data, MSG_NB_SPAWN);
	if (is_closed_map(data->map.array) != 0)
		exit_free_error(data, MSG_MAP_NOT_CLOSED);
}
