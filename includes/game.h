/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 07:25:30 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/22 17:11:22 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

typedef struct s_data	t_data;
typedef struct s_ply	t_ply;
typedef struct s_ray	t_ray;

typedef struct s_game
{
	int		w;
	int		h;
	int		mat_size;
	double	move_speed;
	double	rot_speed;
}	t_game;

/* game */
int		init_game(t_data *data);
/* hooks */
int		close_window(t_data *data);
int		key_pressed(int key, t_data *data);
int		key_release(int key, t_data *data);
/* moves */
void	update_pos(t_data *data, t_ray *ray, char **map, double speed);
/* rotate */
void	update_angle(t_data *data, t_ray *ray, double speed);
/* utils */
void	key_loop(t_data *data);
int		is_character(char c);

#endif
