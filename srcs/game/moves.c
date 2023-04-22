/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:27:55 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/22 17:10:56 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move_up(t_ray *ray, char **map, double speed)
{
	if (map[(int)ray->y][(int)(ray->x + ray->dir_x * speed)] != '1')
		ray->x += ray->dir_x * speed;
	if (map[(int)(ray->y + ray->dir_y * speed)][(int)ray->x] != '1')
		ray->y += ray->dir_y * speed;
}

static void	move_left(t_ray *ray, char **map, double speed)
{
	if (map[(int)ray->y][(int)(ray->x - ray->plane_x * speed)] != '1')
		ray->x -= ray->plane_x * speed;
	if (map[(int)(ray->y - ray->plane_y * speed)][(int)ray->x] != '1')
		ray->y -= ray->plane_y * speed;
}

static void	move_down(t_ray *ray, char **map, double speed)
{
	if (map[(int)ray->y][(int)(ray->x - ray->dir_x * speed)] != '1')
		ray->x -= ray->dir_x * speed;
	if (map[(int)(ray->y - ray->dir_y * speed)][(int)ray->x] != '1')
		ray->y -= ray->dir_y * speed;
}

static void	move_right(t_ray *ray, char **map, double speed)
{
	if (map[(int)ray->y][(int)(ray->x + ray->plane_x * speed)] != '1')
		ray->x += ray->plane_x * speed;
	if (map[(int)(ray->y + ray->plane_y * speed)][(int)ray->x] != '1')
		ray->y += ray->plane_y * speed;
}

void	update_pos(t_data *data, t_ray *ray, char **map, double speed)
{
	if (data->key.w == true)
		move_up(ray, map, speed);
	if (data->key.a == true)
		move_left(ray, map, speed);
	if (data->key.s == true)
		move_down(ray, map, speed);
	if (data->key.d == true)
		move_right(ray, map, speed);
}
