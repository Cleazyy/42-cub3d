/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 10:42:17 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/22 13:10:54 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	initialize_map_table(t_data *data)
{
	int	i;

	data->map.str = NULL;
	data->map.array = NULL;
	i = -1;
	while (++i < 4)
		data->mat[i].path = NULL;
	data->map.floor_color = NULL;
	data->map.ceiling_color = NULL;
	data->map.floor_rgb = 0;
	data->map.ceiling_rgb = 0;
}

static void	initialize_player_table(t_data *data)
{
	data->ply.x = 0;
	data->ply.y = 0;
	data->ply.angle = 0;
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

static void	initialize_ray_table(t_ray *ray)
{
	ray->dir_x = 0;
	ray->dir_y = 0;
	ray->plane_x = 0;
	ray->plane_y = 0;
	ray->cam_x = 0;
	ray->ray_dir_x = 0;
	ray->ray_dir_y = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->delta_dist_x = 0;
	ray->delta_dist_y = 0;
	ray->side_dist_x = 0;
	ray->side_dist_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->side = 0;
	ray->perpwalldist = 0;
	ray->start = 0;
	ray->end = 0;
	ray->wall_x = 0;
	ray->tex_x = 0;
	ray->tex_y = 0;
	ray->step = 0;
	ray->tex_pos = 0;
}

void	parsing_tables_initialization(t_data *data)
{
	data->win_w = WIN_W;
	data->win_h = WIN_H;
	initialize_map_table(data);
	initialize_player_table(data);
	initialize_key_table(data);
	initialize_ray_table(&data->ray);
}