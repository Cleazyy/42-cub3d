/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 08:06:08 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/22 17:00:40 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_loop(t_data *data)
{
	update_pos(data, &data->ply, &data->ray, data->map.array, data->game.move_speed);
	update_angle(data, &data->ray, data->game.rot_speed);
}

int	is_character(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}
