/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 08:26:30 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/21 11:20:44 by fluchten         ###   ########.fr       */
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
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	count_spawn_pos(char **map, t_data *data)
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
				data->map.start_player_x = j;
				data->map.start_player_y = i;
				count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}

int	closed_map(char **map, int j, int i)
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
}

void	check_is_valid_map(t_data *data, char **map)
{
	if (!only_valid_items(map))
		exit_free_error(data, MSG_INVALID_ITEMS);
	else if (count_spawn_pos(map, data) != 1)
		exit_free_error(data, MSG_NB_SPAWN);
	else if (closed_map(map, data->map.start_player_x, data->map.start_player_y))
		exit_free_error(data, "stout");
	print_map_infos(data);
}
