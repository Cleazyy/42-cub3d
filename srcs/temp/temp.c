/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:41:50 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/20 15:57:51 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map_infos(t_data *data)
{
	printf("no_path = %s\n", data->map.sprite.no_path);
	printf("so_path = %s\n", data->map.sprite.so_path);
	printf("we_path = %s\n", data->map.sprite.we_path);
	printf("ea_path = %s\n", data->map.sprite.ea_path);
	printf("floor_color = %s\n", data->map.floor_color);
	printf("ceiling_color = %s\n", data->map.ceiling_color);
}
