/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:00:45 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/22 13:05:05 by fluchten         ###   ########.fr       */
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
	int	i;

	i = 0;
	while (i < 4)
	{
		if (data->mat[i].path)
			free(data->mat[i].path);
		i++;
	}
	if (data->map.floor_color)
		free(data->map.floor_color);
	if (data->map.ceiling_color)
		free(data->map.ceiling_color);
	if (data->map.str)
		free(data->map.str);
	if (data->map.array)
		free_array(data->map.array);
}
