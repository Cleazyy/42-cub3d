/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:08:29 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/09 16:06:10 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# define MINIMAP_WIDTH 175
# define MINIMAP_HEIGHT 175

typedef struct s_data	t_data;

typedef struct s_minimap
{
	int	x;
	int	y;
	int	w;
	int	h;
	int	rect;
	int	clr_back;
	int	clr_out;
	int	clr_wall;
	int	clr_floor;
	int	clr_ply;
}	t_minimap;

/* init */
void	init_minimap(t_data *data);
/* utils */
void	draw_minimap_background(t_data *data, t_minimap *mini);
void	draw_minimap_player(t_data *data, t_minimap *mini);

#endif
