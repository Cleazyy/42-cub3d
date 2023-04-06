/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:30:04 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/06 13:25:29 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include "libft.h"
# include "get_next_line.h"
# include "msg.h"

# define WIN_W 1280
# define WIN_H 720

typedef struct s_sprite
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
}	t_sprite;

typedef struct s_ply
{
	int	s_posx;
	int	s_posy;
}	t_ply;

typedef struct s_map
{
	char		*str;
	char		**array;
	t_sprite	sprite;
	char		*floor_color;
	char		*ceiling_color;
}	t_map;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_ply		ply;
}	t_data;

/* map */
void	check_is_valid_map(t_data *data);
void	parse_map(t_data *data, char *file);
void	initialize_map_table(t_data *data);
int		map_contains_all_infos(t_data *data);
void	print_map_infos(t_data *data);
/* utils */
int		is_character(char c);
/* utils args */
int		check_args(int ac, char **av);
/* utils errors */
int		print_error(char *str);
void	exit_error(char *str);
void	exit_free_error(t_data *data, char *str);
/* utils free */
void	free_array(char **array);
void	free_everythings(t_data *data);
/* utils hooks */
int		close_window(t_data *data);
int		key_pressed(int key, t_data *data);

#endif
