/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 10:42:17 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/22 11:54:41 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void initialize_data_table(t_data *data)
{
	data->win_w = WIN_W;
	data->win_h = WIN_H;
}

static void	initialize_map_table(t_data *data)
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

static void	initialize_key_table(t_data *data)
{
	data->key.w = false;
	data->key.a = false;
	data->key.s = false;
	data->key.d = false;
	data->key.arr_l = false;
	data->key.arr_r = false;
}

void	parsing_tables_initialization(t_data *data)
{
	initialize_data_table(data);
	initialize_map_table(data);
	initialize_key_table(data);
}