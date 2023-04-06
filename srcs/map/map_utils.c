/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 08:44:46 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/06 08:59:02 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map_infos(t_data *data)
{
	int	i;

	printf("no_path = [%s]\n", data->map.sprite.no_path);
	printf("so_path = [%s]\n", data->map.sprite.so_path);
	printf("we_path = [%s]\n", data->map.sprite.we_path);
	printf("ea_path = [%s]\n", data->map.sprite.ea_path);
	printf("floor_color = [%s]\n", data->map.floor_color);
	printf("ceiling_color = [%s]\n", data->map.ceiling_color);
	i = -1;
	while (data->map.array[++i])
		printf("map.array[%d] = [%s]\n", i, data->map.array[i]);
}
