/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:30:04 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/17 09:54:16 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSG_H
# define MSG_H

# define MSG_ERROR "\033[1;31mError\033[0m"

# define MSG_MLX_FAILED "Mlx initialization failed!"

# define MSG_WRONG_NB_ARGS "Wrong number of arguments!"
# define MSG_OPEN_FAILED "Map file opening failed!"
# define MSG_INVALID_MAP "Invalid map format!"

# define MSG_INVALID_ITEMS "Map contains invalid items!"
# define MSG_NB_SPAWN "Map does not exactly have a spawn!"
# define MSG_MAP_NOT_CLOSED "Map is not surrounded by walls!"
# define MSG_MAP_ALL_INFOS "Map does not contain all the information \
or it is not in the right place!"
# define MSG_MAP_DUP_INFO "Map contains duplicate information!"
# define MSG_MAP_NEWLINE "Map contains a newline!"
# define MSG_SYNTAX_ERROR "Map syntax error!"

# define MSG_MINIMAP_SIZE "Dimensions of the minimap are too large!"

#endif
