/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 08:06:08 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/22 20:14:33 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_loop(t_data *data)
{
	update_pos(data, &data->ray, data->map.array, data->game.move_speed);
	update_angle(data, &data->map, &data->ray, data->game.rot_speed);
}

int	is_character(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	is_north_or_south(char c)
{
	return (c == 'N' || c == 'S');
}

int	is_east_or_weast(char c)
{
	return (c == 'E' || c == 'W');
}
