/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:27:55 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/22 15:44:53 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move_up(t_ply *ply, t_ray *ray, char **map, double speed)
{
	if (map[(int)ply->y][(int)(ply->x + ray->dir_x * speed)] != '1')
		ply->x += ray->dir_x * speed;
	if (map[(int)(ply->y + ray->dir_y * speed)][(int)ply->x] != '1')
		ply->y += ray->dir_y * speed;
}

static void	move_left(t_ply *ply, t_ray *ray, char **map, double speed)
{
	if(map[(int)ply->y][(int)(ply->x - ray->plane_x * speed)] != '1')
		ply->x -= ray->plane_x * speed;
	if(map[(int)(ply->y - ray->plane_y * speed)][(int)ply->x] != '1')
		ply->y -= ray->plane_y * speed;
}

static void	move_down(t_ply *ply, t_ray *ray, char **map, double speed)
{
	if(map[(int)ply->y][(int)(ply->x - ray->dir_x * speed)] != '1')
		ply->x -= ray->dir_x * speed;
	if(map[(int)(ply->y - ray->dir_y * speed)][(int)ply->x] != '1')
		ply->y -= ray->dir_y * speed;
}

static void	move_right(t_ply *ply, t_ray *ray, char **map, double speed)
{
	if (map[(int)ply->y][(int)(ply->x + ray->plane_x * speed)] != '1')
		ply->x += ray->plane_x * speed;
	if (map[(int)(ply->y + ray->plane_y * speed)][(int)ply->x] != '1')
		ply->y += ray->plane_y * speed;
}

void	update_pos(t_data *data, t_ply *ply, t_ray *ray, char **map, double speed)
{
	if (data->key.w == true)
		move_up(ply, ray, map, speed);
	if (data->key.a == true)
		move_left(ply, ray, map, speed);
	if (data->key.s == true)
		move_down(ply, ray, map, speed);
	if (data->key.d == true)
		move_right(ply, ray, map, speed);
}