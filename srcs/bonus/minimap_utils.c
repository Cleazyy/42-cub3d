/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:30:46 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/09 15:59:49 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	draw_minimap_player(t_data *data, t_minimap *mini)
{
	double	pos_x;
	double	pos_y;
	int		y;
	int		x;

	pos_x = mini->x + (mini->w / 2) - (mini->rect / 2);
	pos_y = mini->y + (mini->h / 2) - (mini->rect / 2);
	y = 0;
	while (y < mini->rect)
	{
		x = 0;
		while (x < mini->rect)
		{
			ft_mlx_pixel_put(&data->img, pos_x + x, pos_y + y, mini->clr_ply);
			x++;
		}	
		y++;
	}
}
