/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 09:27:15 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/21 12:01:34 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
}

static void	update_delta_dist(t_ray *ray)
{
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
}

static void	update_steps(t_ray *ray, t_ply *ply)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (ply->x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - ply->x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (ply->y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - ply->y) * ray->delta_dist_y;
	}
}

static void	dda_algorithm(t_data *data, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (data->map.array[ray->map_y][ray->map_y] == '1')
			hit = 1;
	}
}

static void	update_values(t_data *data, t_ray *ray, int x)
{
	ray->dir_x = 0;
	ray->dir_y = -1;
	ray->plane_x = 0.66;
	ray->plane_y = 0;
	ray->cam_x = 2 * x / (double) data->win_w - 1;
	ray->ray_dir_x = ray->dir_x + ray->plane_x * ray->cam_x;
	ray->ray_dir_y = ray->dir_y + ray->plane_y * ray->cam_x;
	ray->map_x = (int) data->ply.x;
	ray->map_y = (int) data->ply.y;
	update_delta_dist(ray);
	update_steps(ray, &data->ply);
	dda_algorithm(data, ray);
	if (ray->side == 0)
		ray->perpwalldist = (ray->side_dist_y - ray->delta_dist_x);
	else
		ray->perpwalldist = (ray->side_dist_y - ray->delta_dist_y);
}

void	raycasting(t_data *data)
{
	int	x;

	initialize_ray_table(&data->ray);
	x = 0;
	while (x < data->win_w)
	{
		update_values(data, &data->ray, x);
		x++;
	}
}
