/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:26:19 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/23 09:54:52 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	initialize_minimap_table(t_data *data, t_minimap *mini)
{
	mini->data = data;
	mini->x = 10;
	mini->y = 10;
	mini->w = 190;
	if (mini->w > (data->win_w - (mini->x * 2)))
		exit_free_error(data, MSG_MINIMAP_SIZE);
	mini->h = 190;
	if (mini->h > (data->win_h - (mini->y * 2)))
		exit_free_error(data, MSG_MINIMAP_SIZE);
	mini->rect = 10;
	mini->scale = mini->rect * 2;
	mini->clr_back = 0x1e202a;
	mini->clr_out = 0x63656e;
	mini->clr_wall = 0x2b2d3d;
	mini->clr_floor = 0x63656e;
	mini->clr_ply = 0xff0000;
}

void	init_minimap(t_data *data)
{
	t_minimap	mini;

	initialize_minimap_table(data, &mini);
	draw_minimap_background(data, &mini);
	draw_minimap_map(&data->ray, &mini, data->map.array);
	draw_minimap_player(&mini);
}
