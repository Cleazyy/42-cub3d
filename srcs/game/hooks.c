/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:11:19 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/12 10:48:10 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_window(t_data *data)
{
	ft_putendl_fd("Game closed.", STDOUT_FILENO);
	mlx_destroy_window(data->mlx, data->win);
	free_everythings(data);
	exit(EXIT_SUCCESS);
}

void	update_pos(t_data *data, int key)
{
	double	side_x;
	double	side_y;

	side_x = cos(data->ply.angle + (M_PI / 2)) / 5;
	side_y = sin(data->ply.angle + (M_PI / 2)) / 5;
	if (key == KEY_UP)
	{
		data->ply.x -= side_y;
		data->ply.y += side_x;
	}
	if (key == KEY_LEFT)
	{
		data->ply.x += side_x;
		data->ply.y -= side_y;
	}
	if (key == KEY_DOWN)
	{
		data->ply.x += side_y;
		data->ply.y -= side_x;
	}
	if (key == KEY_RIGHT)
	{
		data->ply.x -= side_x;
		data->ply.y += side_y;
	}
}

void	update_angle(t_data *data, int key)
{
	if (key == KEY_A_L)
		data->ply.angle -= 0.1;
	if (key == KEY_A_R)
		data->ply.angle += 0.1;
}

int	key_pressed(int key, t_data *data)
{
	if (key == KEY_CLOSE)
		close_window(data);
	update_pos(data, key);
	update_angle(data, key);
	return (0);
}
