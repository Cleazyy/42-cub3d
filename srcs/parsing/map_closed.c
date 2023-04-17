/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_closed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 09:54:45 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/17 10:32:09 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_valid_pos(char **map, int x, int y)
{
	if (y < 0 || y >= ft_array_len(map))
		return (1);
	if (x < 0 || x >= (int) ft_strlen(map[y]))
		return (1);
	if (map[y][x] == ' ')
		return (1);
	return (0);
}

static int	check_around_pos(char **map, int x, int y)
{
	if (is_valid_pos(map, y - 1, x) != 0)
		return (1);
	if (is_valid_pos(map, y + 1, x) != 0)
		return (1);
	if (is_valid_pos(map, y, x - 1) != 0)
		return (1);
	if (is_valid_pos(map, y, x + 1) != 0)
		return (1);
	return (0);
}

int	is_closed_map(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '0' || is_character(map[y][x]))
				if (check_around_pos(map, y, x) != 0)
					return (1);
			x++;
		}
		y++;
	}
	return (0);
}
