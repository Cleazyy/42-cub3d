/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:28:20 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/08 12:31:53 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (check_args(ac, av) != 0)
		return (1);
	parse_map(&data, av[1]);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (print_error(MSG_MLX_FAILED));
	data.win = mlx_new_window(data.mlx, WIN_W, WIN_H, "cub3d");
	if (!data.win)
		return (print_error(MSG_MLX_FAILED));
	mlx_key_hook(data.win, key_pressed, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
	return (0);
}
