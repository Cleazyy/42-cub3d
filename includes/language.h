/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   language.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 07:25:30 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/22 16:58:11 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LANGUAGE_H
# define LANGUAGE_H

/* base */
# define MSG_ERROR "\033[1;31mError\033[0m"
# define MSG_MALLOC_ERR "malloc() failed!"

/* game */
# define MSG_MLX_FAILED "Mlx initialization failed!"

/* minimap */
# define MSG_MINIMAP_SIZE "Dimensions of the minimap are too large!"

/* parsing */
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

#endif
