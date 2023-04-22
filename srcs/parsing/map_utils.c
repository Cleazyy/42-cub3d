/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 08:44:46 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/22 16:38:19 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_contains_all_infos(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!data->mat[i].path)
			return (1);
		i++;
	}
	if (!data->map.floor_color || !data->map.ceiling_color)
		return (1);
	return (0);
}

void	print_map_infos(t_data *data)
{
	int	i;

	printf("no_path = [%s]\n", data->mat[NO].path);
	printf("so_path = [%s]\n", data->mat[SO].path);
	printf("we_path = [%s]\n", data->mat[WE].path);
	printf("ea_path = [%s]\n", data->mat[EA].path);
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
