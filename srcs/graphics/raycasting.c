/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 09:27:15 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/21 18:50:05 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* static void	initialize_ray_table(t_ray *ray)
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
} */

static int	get_line_height(t_data *data)
{
	return ((int)(data->win_h / data->ray.perpwalldist));
}

static int	get_lowest_pixel(t_data *data, int *line_height)
{
	int	draw_start;

	draw_start = -*line_height / 2 + data->win_h / 2;
	if (draw_start < 0)
		draw_start = 0;
	return (draw_start);
}

static int	get_highest_pixel(t_data *data, int *line_height)
{
	int	draw_end;

	draw_end = *line_height / 2 + data->win_h / 2;
	if (draw_end >= data->win_h)
		draw_end = data->win_h - 1;
	return (draw_end);
}

static void	jsp(t_data *data, t_ray *ray, int line_height)
{
	if (ray->side == 0)
		ray->wall_x = data->ply.y + ray->perpwalldist * ray->ray_dir_y;
	else
		ray->wall_x = data->ply.x + ray->perpwalldist * ray->ray_dir_x;
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = ray->wall_x * 128;
	if (ray->side == 0 && ray->ray_dir_x > 0)
		ray->tex_x = 128 - ray->tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		ray->tex_x = 128 - ray->tex_x - 1;
	ray->step = 1.0 * 128 / line_height;
	ray->tex_pos = (ray->start - data->win_h / 2 + line_height / 2) * ray->step;
}

static void	draw(t_data *data, t_ray *ray, int x, int color)
{
	ft_mlx_pixel_put(&data->img, x, ray->start, color);
}

static void	draw_column(t_data *data, t_ray *ray, int x)
{
	int	line_height;

	line_height = get_line_height(data);
	ray->start = get_lowest_pixel(data, &line_height);
	ray->end = get_highest_pixel(data, &line_height);
	jsp(data, &data->ray, line_height);
	while (ray->start < ray->end)
	{
		ray->tex_y = (int) ray->tex_pos & (128 - 1);
		ray->tex_pos += ray->step;
		if (ray->side == 1 && ray->ray_dir_y > 0)
			draw(data, &data->ray, x, 0xe5ff00);
		else if (ray->side == 1 && ray->ray_dir_y < 0)
			draw(data, &data->ray, x, 0x00fff7);
		else if (ray->side == 0 && ray->ray_dir_x < 0)
			draw(data, &data->ray, x, 0x7500fa);
		else if (ray->side == 0 && ray->ray_dir_x > 0)
			draw(data, &data->ray, x, 0x00fa19);
		ray->start++;
	}
}

void	raycasting(t_data *data)
{
	int	x;

	// initialize_ray_table(&data->ray);
	x = 0;
	while (x < data->win_w)
	{
		update_ray_values(data, &data->ray, x);
		draw_column(data, &data->ray, x);
		x++;
	}
}
