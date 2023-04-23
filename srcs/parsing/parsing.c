/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:49:12 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/23 17:25:41 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* skip_file_spaces removes the front and back spaces
for each information in the map. */
static char	*skip_file_spaces(t_data *data, char *line)
{
	char	*final;
	char	*temp;

	temp = ft_strtrim(line, " ");
	if (!temp)
		exit_free_error(data, MSG_MALLOC_ERR);
	if ((ft_strncmp("NO ", temp, 3) == 0)
		|| (ft_strncmp("SO ", temp, 3) == 0)
		|| (ft_strncmp("WE ", temp, 3) == 0)
		|| (ft_strncmp("EA ", temp, 3) == 0)
		|| (ft_strncmp("F ", temp, 2) == 0)
		|| (ft_strncmp("C ", temp, 2) == 0))
		return (temp);
	else
	{
		free(temp);
		final = ft_strdup(line);
		if (!final)
			exit_free_error(data, MSG_MALLOC_ERR);
		return (final);
	}
}

/* read_file reads the map file line by line using get_next_line */
static void	read_file(t_data *data, char *file)
{
	char	*line;
	char	*temp;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_error(MSG_OPEN_FAILED);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp = skip_file_spaces(data, line);
		free(line);
		parse_map(data, temp);
		free(temp);
	}
}

/* init_parsing initializes the parsing and calls the other functions */
void	init_parsing(t_data *data, int ac, char **av)
{
	char	*file;

	if (check_args_nb(ac) != 0)
		exit_error(MSG_WRONG_NB_ARGS);
	if (check_map_name(av) != 0)
		exit_error(MSG_INVALID_MAP);
	file = av[1];
	parsing_tables_initialization(data);
	read_file(data, file);
	data->map.array = ft_split(data->map.str, '\n');
	if (!data->map.array)
		exit_free_error(data, MSG_MALLOC_ERR);
	data->map.floor_rgb = parse_colors(data, data->map.floor_color);
	data->map.ceiling_rgb = parse_colors(data, data->map.ceiling_color);
	check_is_valid_map(data);
	init_player_infos(data);
	print_map_infos(data);
}
