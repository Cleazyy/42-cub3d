/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:30:33 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/19 07:32:54 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

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

typedef struct s_data	t_data;

/* args */
int		check_args_nb(int ac);
int		check_map_name(char **av);
/* colors */
int		parse_colors(t_data *data, char *color);
/* map checks */
void	check_is_valid_map(t_data *data);
/* map closed */
int		is_closed_map(char **map);
/* map utils */
void	initialize_map_table(t_data *data);
int		map_contains_all_infos(t_data *data);
void	print_map_infos(t_data *data);
void	parse_map(t_data *data, char *line);
/* parsing */
void	init_parsing(t_data *data, int ac, char **av);
/* player */
void	init_player_infos(t_data *data);

#endif
