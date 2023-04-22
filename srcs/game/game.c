/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:29:04 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/22 11:49:34 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	game_loop(t_data *data)
{
	key_loop(data);
	draw_background(data);
	raycasting(data);
	// draw_angle(data);
	// init_minimap(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.ptr, 0, 0);
	return (0);
}

static void	init_game_hooks(t_data *data)
{
	mlx_hook(data->win, 2, 0, key_pressed, data);
	mlx_hook(data->win, 3, 0, key_release, data);
	mlx_hook(data->win, 17, 0, close_window, data);
	mlx_loop_hook(data->mlx, game_loop, data);
	mlx_loop(data->mlx);
}

static int	init_game_img(t_data *data)
{
	data->img.ptr = mlx_new_image(data->mlx, data->win_w, data->win_h);
	if (!data->img.ptr)
		return (1);
	data->img.addr = mlx_get_data_addr(data->img.ptr, &data->img.bpp, &data->img.line_length, &data->img.endian);
	if (!data->img.addr)
		return (1);
	return (0);
}

int	init_game(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (1);
	data->win = mlx_new_window(data->mlx, data->win_w, data->win_h, "cub3d");
	if (!data->win)
		return (1);
	if (init_game_img(data) != 0)
		return (1);
	init_game_hooks(data);
	return (0);
}
