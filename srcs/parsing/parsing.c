/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:49:12 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/17 10:43:02 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*skip_file_spaces(t_data *data, char *line)
{
	char	*final;
	char	*temp;

	temp = ft_strtrim(line, " ");
	if (!temp)
		exit_free_error(data, MSG_MALLOC_ERR);
	if ((temp[0] == 'N' && temp[1] == 'O')
		|| (temp[0] == 'S' && temp[1] == 'O')
		|| (temp[0] == 'W' && temp[1] == 'E')
		|| (temp[0] == 'E' && temp[1] == 'A')
		|| (temp[0] == 'F')
		|| (temp[0] == 'C'))
		return (temp);
	else
	{
		final = ft_strdup(line);
		return (final);
	}
}

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

void	init_parsing(t_data *data, int ac, char **av)
{
	char	*file;

	if (check_args_nb(ac) != 0)
		exit_error(MSG_WRONG_NB_ARGS);
	if (check_map_name(av) != 0)
		exit_error(MSG_INVALID_MAP);
	file = av[1];
	initialize_map_table(data);
	initialize_key_table(data);
	read_file(data, file);
	data->map.array = ft_split(data->map.str, '\n');
	if (!data->map.array)
		exit_free_error(data, MSG_MALLOC_ERR);
	data->map.floor_rgb = parse_colors(data, data->map.floor_color);
	data->map.ceiling_rgb = parse_colors(data, data->map.ceiling_color);
	check_is_valid_map(data);
	data->win_w = WIN_W;
	data->win_h = WIN_H;
	init_player_infos(data);
	print_map_infos(data);
}
