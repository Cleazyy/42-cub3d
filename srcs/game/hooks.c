/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:11:19 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/22 17:25:34 by fluchten         ###   ########.fr       */
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
	if (key == KEY_ESC)
		close_window(data);
	if (key == KEY_W)
		data->key[W] = true;
	if (key == KEY_A)
		data->key[A] = true;
	if (key == KEY_S)
		data->key[S] = true;
	if (key == KEY_D)
		data->key[D] = true;
	if (key == KEY_L)
		data->key[L] = true;
	if (key == KEY_R)
		data->key[R] = true;
	return (0);
}

int	key_release(int key, t_data *data)
{
	if (key == KEY_W)
		data->key[W] = false;
	if (key == KEY_A)
		data->key[A] = false;
	if (key == KEY_S)
		data->key[S] = false;
	if (key == KEY_D)
		data->key[D] = false;
	if (key == KEY_L)
		data->key[L] = false;
	if (key == KEY_R)
		data->key[R] = false;
	return (0);
}
