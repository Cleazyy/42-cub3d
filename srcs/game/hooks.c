/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:11:19 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/13 08:48:22 by fluchten         ###   ########.fr       */
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

int	key_pressed(int key, t_data *data)
{
	if (key == KEY_CLOSE)
		close_window(data);
	if (key == KEY_UP)
		data->key.w = true;
	if (key == KEY_LEFT)
		data->key.a = true;
	if (key == KEY_DOWN)
		data->key.s = true;
	if (key == KEY_RIGHT)
		data->key.d = true;
	if (key == KEY_ARR_L)
		data->key.arr_l = true;
	if (key == KEY_ARR_R)
		data->key.arr_r = true;
	return (0);
}

int	key_release(int key, t_data *data)
{
	if (key == KEY_UP)
		data->key.w = false;
	if (key == KEY_LEFT)
		data->key.a = false;
	if (key == KEY_DOWN)
		data->key.s = false;
	if (key == KEY_RIGHT)
		data->key.d = false;
	if (key == KEY_ARR_L)
		data->key.arr_l = false;
	if (key == KEY_ARR_R)
		data->key.arr_r = false;
	return (0);
}
