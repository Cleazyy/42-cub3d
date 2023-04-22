/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:28:20 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/22 11:49:48 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;

	init_parsing(&data, ac, av);
	if (init_game(&data) != 0)
		exit_free_error(&data, MSG_MLX_FAILED);
	return (0);
}
