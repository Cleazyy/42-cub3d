/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:26:19 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/24 10:31:49 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* initialize_minimap_table initializes the variables of the minimap
structure and check if its size is not bigger than the window */
static int	initialize_minimap_table(t_data *data, t_minimap *mini)
{
	mini->data = data;
	mini->x = 10;
	mini->y = 10;
	mini->w = 190;
	if (mini->w > (data->win_w - (mini->x * 2)))
		return (1);
	mini->h = 190;
	if (mini->h > (data->win_h - (mini->y * 2)))
		return (1);
	mini->rect = 10;
	mini->scale = mini->rect * 2;
	mini->clr_back = 0x1e202a;
	mini->clr_out = 0x63656e;
	mini->clr_wall = 0x2b2d3d;
	mini->clr_floor = 0x63656e;
	mini->clr_ply = 0xff0000;
	return (0);
}

/* init_minimap displays the minimap in the window */
void	init_minimap(t_data *data)
{
	t_minimap	mini;

	if (initialize_minimap_table(data, &mini) != 0)
		return ;
	draw_minimap_background(data, &mini);
	draw_minimap_map(&data->ray, &mini, data->map.array);
	draw_minimap_player(&mini);
}
