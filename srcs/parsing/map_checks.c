/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 08:26:30 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/10 15:27:56 by fluchten         ###   ########.fr       */
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
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != ' '
				&& !is_character(map[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	count_spawn_pos(char **map)
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
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	check_is_valid_map(t_data *data)
{
	if (only_valid_items(data->map.array) != 0)
		exit_free_error(data, MSG_INVALID_ITEMS);
	if (count_spawn_pos(data->map.array) != 1)
		exit_free_error(data, MSG_NB_SPAWN);
}
