/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:28:20 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/11 14:53:32 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;

	init_parsing(&data, ac, av);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (print_error(MSG_MLX_FAILED));
	data.win = mlx_new_window(data.mlx, data.win_w, data.win_h, "cub3d");
	if (!data.win)
		return (print_error(MSG_MLX_FAILED));
	data.img.ptr = mlx_new_image(data.mlx, data.win_w, data.win_h);
	data.img.addr = mlx_get_data_addr(data.img.ptr, &data.img.bpp,
			&data.img.line_len, &data.img.endian);
	mlx_key_hook(data.win, key_pressed, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop_hook(data.mlx, init_game, &data);
	mlx_loop(data.mlx);
	return (0);
}
