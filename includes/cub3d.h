/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:30:04 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/19 16:13:22 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <mlx.h>
# include "libft.h"
# include "msg.h"

typedef struct s_game {
	void	*mlx;
	void	*win;
}	t_game;

/* game */
int		close_window(t_game *game);
int		key_pressed(int key, t_game *game);
/* utils args */
int		check_args(int ac, char **av);
/* utils errors */
int		print_error(char *str);

#endif
