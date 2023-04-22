/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 09:27:15 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/22 16:34:06 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_raycasting(t_data *data)
{
	int	x;

	x = 0;
	while (x < data->win_w)
	{
		update_player_infos(data, &data->ray, x);
		draw_map(data, &data->ray, x);
		x++;
	}
}
