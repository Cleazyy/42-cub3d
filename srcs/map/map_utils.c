/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 08:44:46 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/06 13:25:14 by fluchten         ###   ########.fr       */
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
}

int	map_contains_all_infos(t_data *data)
{
	if (!data->map.sprite.no_path)
		return (1);
	if (!data->map.sprite.so_path)
		return (1);
	if (!data->map.sprite.we_path)
		return (1);
	if (!data->map.sprite.ea_path)
		return (1);
	if (!data->map.floor_color)
		return (1);
	if (!data->map.ceiling_color)
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
	i = -1;
	while (data->map.array[++i])
		printf("map.array[%d] = [%s]\n", i, data->map.array[i]);
}
