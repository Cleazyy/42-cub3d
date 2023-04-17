/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:00:45 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/17 09:19:09 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_everythings(t_data *data)
{
	if (data->map.sprite.no_path)
		free(data->map.sprite.no_path);
	if (data->map.sprite.so_path)
		free(data->map.sprite.so_path);
	if (data->map.sprite.we_path)
		free(data->map.sprite.we_path);
	if (data->map.sprite.ea_path)
		free(data->map.sprite.ea_path);
	if (data->map.floor_color)
		free(data->map.floor_color);
	if (data->map.ceiling_color)
		free(data->map.ceiling_color);
	if (data->map.str)
		free(data->map.str);
	if (data->map.array)
		free_array(data->map.array);
}
