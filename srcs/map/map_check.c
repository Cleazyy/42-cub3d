/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 08:26:30 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/21 09:20:11 by fluchten         ###   ########.fr       */
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

void	check_is_valid_map(t_data *data, char **map)
{
	if (!only_valid_items(map))
		exit_free_error(data, "Map contains invalid items!");
	else if (count_spawn_pos(map) != 1)
		exit_free_error(data, "Map does not exactly have a spawn!");
}
