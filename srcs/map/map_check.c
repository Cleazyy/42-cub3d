/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 08:26:30 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/06 08:31:56 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	only_valid_items(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!is_character(map[i][j]) && map[i][j] != '0' && map[i][j] != '1'
				&& map[i][j] != ' ')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	count_spawn_pos(t_data *data, char **map)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_character(map[i][j]))
			{
				data->ply.s_posy = i;
				data->ply.s_posx = j;
				count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}

/* static int	closed_map(char **map, int j, int i)
{
	int	ret;

	if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'N')
		return (1);
	if (map[i][j] != '1')
	{
		map[i][j] = '1';
		ret = closed_map(map, j + 1, i);
		if (ret)
			return (1);
		ret = closed_map(map, j, i + 1);
		if (ret)
			return (1);
		ret = closed_map(map, j - 1, i);
		if (ret)
			return (1);
		return (closed_map(map, j, i - 1));
	}
	return (0);
} */

void	check_is_valid_map(t_data *data)
{
	if (only_valid_items(data->map.array) != 0)
		exit_free_error(data, MSG_INVALID_ITEMS);
	if (count_spawn_pos(data, data->map.array) != 1)
		exit_free_error(data, MSG_NB_SPAWN);
	// if (closed_map(data->map.array, data->ply.s_posx, data->ply.s_posy) != 0)
	// 	exit_free_error(data, MSG_MAP_NOT_CLOSED);
}
