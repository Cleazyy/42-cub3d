/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 08:44:46 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/06 22:39:31 by fluchten         ###   ########.fr       */
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

char	*remove_map_spaces_infos(char *line)
{
	char	*final;
	char	*temp;

	temp = ft_strtrim(line, " ");
	if ((temp[0] == 'N' && temp[1] == 'O')
		|| (temp[0] == 'S' && temp[1] == 'O')
		|| (temp[0] == 'W' && temp[1] == 'E')
		|| (temp[0] == 'E' && temp[1] == 'A')
		|| (temp[0] == 'F')
		|| (temp[0] == 'C'))
		return (temp);
	else
	{
		final = ft_strdup(line);
		return (final);
	}
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
}
