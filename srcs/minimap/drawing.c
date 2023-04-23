/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:30:46 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/23 16:28:59 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* draw_minimap_rect draws a square at the positions passed in parameters,
checking not to exceed the limits of the minimap */
void	draw_minimap_rect(t_minimap *mini, double px, double py, int color)
{
	int	y;
	int	x;

	y = 0;
	while (y < mini->rect)
	{
		x = 0;
		while (x < mini->rect)
		{
			if ((px + x > mini->x) && (px + x < mini->w + mini->x)
				&& (py + y > mini->y) && (py + y < mini->h + mini->y))
				ft_mlx_pixel_put(&mini->data->img, px + x, py + y, color);
			x++;
		}	
		y++;
	}
}

/* draw_minimap_background draws the minimap and its outline */
void	draw_minimap_background(t_data *data, t_minimap *mini)
{
	int	y;
	int	x;

	y = 0;
	while (y < mini->h)
	{
		x = 0;
		while (x < mini->w)
		{
			ft_mlx_pixel_put(&data->img, mini->x + x, mini->y + y,
				mini->clr_back);
			ft_mlx_pixel_put(&data->img, mini->x + x, mini->y,
				mini->clr_out);
			ft_mlx_pixel_put(&data->img, mini->x + x, mini->y + mini->h,
				mini->clr_out);
			ft_mlx_pixel_put(&data->img, mini->x, mini->y + y,
				mini->clr_out);
			ft_mlx_pixel_put(&data->img, mini->x + mini->w, mini->y + y,
				mini->clr_out);
			x++;
		}
		y++;
	}
}

/* draw_minimap_map draws a square for each floor and for each wall
depending on the position of the player */
void	draw_minimap_map(t_ray *ray, t_minimap *mini, char **map)
{
	double	pos_x;
	double	pos_y;
	int		y;
	int		x;

	pos_x = 0;
	pos_y = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			pos_x = ((mini->w / mini->scale) - (ray->x - x))
				* mini->rect + mini->x;
			pos_y = ((mini->h / mini->scale) - (ray->y - y))
				* mini->rect + mini->y;
			if (map[y][x] == '1')
				draw_minimap_rect(mini, pos_x, pos_y, mini->clr_wall);
			if (map[y][x] == '0' || is_character(map[y][x]))
				draw_minimap_rect(mini, pos_x, pos_y, mini->clr_floor);
			x++;
		}
		y++;
	}
}

/* draw_minimap_player draws the player square in the middle of the minimap */
void	draw_minimap_player(t_minimap *mini)
{
	double	pos_x;
	double	pos_y;

	pos_x = mini->x + (mini->w / 2) - (mini->rect);
	pos_y = mini->y + (mini->h / 2) - (mini->rect);
	draw_minimap_rect(mini, pos_x, pos_y, mini->clr_ply);
}
