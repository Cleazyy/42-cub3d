/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:00:45 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/20 16:03:15 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_everythings(t_data *data)
{
	free(data->map.sprite.no_path);
	free(data->map.sprite.so_path);
	free(data->map.sprite.we_path);
	free(data->map.sprite.ea_path);
	free(data->map.floor_color);
	free(data->map.ceiling_color);
}