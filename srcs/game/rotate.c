/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:27:53 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/22 15:38:04 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	rotate_angle(t_ray *ray, double speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = ray->dir_x;
	ray->dir_x = ray->dir_x * cos(speed) - ray->dir_y * sin(speed);
	ray->dir_y = old_dir_x * sin(speed) + ray->dir_y * cos(speed);
	old_plane_x = ray->plane_x;
	ray->plane_x = ray->plane_x * cos(speed) - ray->plane_y * sin(speed);
	ray->plane_y = old_plane_x * sin(speed) + ray->plane_y * cos(speed);
}

void	update_angle(t_data *data, t_ray *ray, double speed)
{
	if (data->key.arr_l == true)
		rotate_angle(ray, -speed);
	if (data->key.arr_r == true)
		rotate_angle(ray, speed);
}
