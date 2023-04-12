/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 08:44:46 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/12 07:58:25 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialize_map_table(t_data *data)
{
	data->map.str = NULL;
	data->map.array = NULL;
	data->map.sprite.no_path = NULL;
	data->map.sprite.so_path = NULL;
	data->map.sprite.we_path = NULL;
	data->map.sprite.ea_path = NULL;
	data->map.floor_color = NULL;
	data->map.ceiling_color = NULL;
	data->map.floor_rgb = 0;
	data->map.ceiling_rgb = 0;
}

int	map_contains_all_infos(t_data *data)
{
	if (!data->map.sprite.no_path
		|| !data->map.sprite.so_path
		|| !data->map.sprite.we_path
		|| !data->map.sprite.ea_path
		|| !data->map.floor_color
		|| !data->map.ceiling_color)
		return (1);
	return (0);
}

void	print_map_infos(t_data *data)
{
	int	i;

	printf("no_path = [%s]\n", data->map.sprite.no_path);
	printf("so_path = [%s]\n", data->map.sprite.so_path);
	printf("we_path = [%s]\n", data->map.sprite.we_path);
	printf("ea_path = [%s]\n", data->map.sprite.ea_path);
	printf("floor_color = [%s]\n", data->map.floor_color);
	printf("ceiling_color = [%s]\n", data->map.ceiling_color);
	printf("floor_rgb = [%d]\n", data->map.floor_rgb);
	printf("ceiling_rgb = [%d]\n", data->map.ceiling_rgb);
	i = -1;
	while (data->map.array[++i])
		printf("map.array[%d] = [%s]\n", i, data->map.array[i]);
	printf("ply.x = %f\n", data->ply.x);
	printf("ply.y = %f\n", data->ply.y);
	printf("ply.angle = %f\n", data->ply.angle);
}
