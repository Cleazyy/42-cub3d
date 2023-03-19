/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:28:20 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/19 16:16:44 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (!check_args(ac, av))
		return (1);
	game.mlx = mlx_init();
	if (!game->mlx)
		return (1);
	game.win = mlx_new_window(game.mlx, 500, 500, "cub3d");
	mlx_key_hook(game.win, key_pressed, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop(game.mlx);
	return (0);
}
