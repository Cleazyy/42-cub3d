/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:11:19 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/11 20:38:11 by fluchten         ###   ########.fr       */
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
		data->ply.y -= 0.5;
	if (key == KEY_LEFT)
		data->ply.x -= 0.5;
	if (key == KEY_DOWN)
		data->ply.y += 0.5;
	if (key == KEY_RIGHT)
		data->ply.x += 0.5;
	return (0);
}
