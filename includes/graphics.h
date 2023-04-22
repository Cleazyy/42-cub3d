/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 07:25:30 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/22 13:18:39 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

typedef struct s_img	t_img;
typedef struct s_ply	t_ply;
typedef struct s_data	t_data;

typedef struct s_ray
{
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	cam_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	double	step_x;
	double	step_y;
	double	side;
	double	perpwalldist;
	int		start;
	int		end;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_pos;
}	t_ray;

/* raycasting */
void	update_player_ray(t_data *data, t_ray *ray, int x);
void	raycasting(t_data *data);
/* draw_bg */
void	draw_background(t_data *data);
/* draw_line */
void	draw_line(t_data *data, t_ply *player);
/* draw_pixel */
void	ft_mlx_pixel_put(t_img *img, int x, int y, int color);
/* utils */
void	draw_angle(t_data *data);

#endif
