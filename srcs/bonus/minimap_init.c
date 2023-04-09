/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:26:19 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/09 16:06:12 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	initialize_minimap_table(t_minimap *mini)
{
	mini->x = 10;
	mini->y = 10;
	mini->w = MINIMAP_WIDTH;
	mini->h = MINIMAP_HEIGHT;
	mini->rect = 8;
	mini->clr_back = 0x1e202a;
	mini->clr_out = 0x63656e;
	mini->clr_wall = 0x2b2d3d;
	mini->clr_floor = 0x63656e;
	mini->clr_ply = 0xff0000;
}

void	init_minimap(t_data *data)
{
	t_minimap	mini;

	initialize_minimap_table(&mini);
	draw_minimap_background(data, &mini);
	draw_minimap_player(data, &mini);
}
