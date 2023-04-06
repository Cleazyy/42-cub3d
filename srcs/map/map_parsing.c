/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:49:12 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/06 13:25:06 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*allocate_map_infos(t_data *data, char *line, int start, int info)
{
	char	*final;
	char	*temp;
	int		new_line;
	int		len;

	if ((info == 1 && data->map.sprite.no_path)
		|| (info == 2 && data->map.sprite.so_path)
		|| (info == 3 && data->map.sprite.we_path)
		|| (info == 4 && data->map.sprite.ea_path)
		|| (info == 5 && data->map.floor_color)
		|| (info == 6 && data->map.ceiling_color))
		exit_free_error(data, MSG_MAP_DUP_INFO);
	new_line = 0;
	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		new_line = 1;
	temp = ft_substr(line, start, (len - start) - new_line);
	final = ft_strtrim(temp, " ");
	free(temp);
	return (final);
}

static void	allocate_map(t_data *data, char *line)
{
	char	*temp;

	if (map_contains_all_infos(data) != 0)
		exit_free_error(data, MSG_MAP_ALL_INFOS);
	temp = ft_strdup(data->map.str);
	free(data->map.str);
	data->map.str = ft_strjoin(temp, line);
	free(temp);
}

static void	retrieve_map_infos(t_data *data, char *line)
{
	static int	is_in_map = 0;

	if (line[0] == 'N' && line[1] == 'O')
		data->map.sprite.no_path = allocate_map_infos(data, line, 3, 1);
	else if (line[0] == 'S' && line[1] == 'O')
		data->map.sprite.so_path = allocate_map_infos(data, line, 3, 2);
	else if (line[0] == 'W' && line[1] == 'E')
		data->map.sprite.we_path = allocate_map_infos(data, line, 3, 3);
	else if (line[0] == 'E' && line[1] == 'A')
		data->map.sprite.ea_path = allocate_map_infos(data, line, 3, 4);
	else if (line[0] == 'F')
		data->map.floor_color = allocate_map_infos(data, line, 2, 5);
	else if (line[0] == 'C')
		data->map.ceiling_color = allocate_map_infos(data, line, 2, 6);
	else if (line[0] == '1' || line[0] == '0' || line[0] == ' ')
	{
		is_in_map = 1;
		allocate_map(data, line);
	}
	else if (line[0] == '\n' && is_in_map == 1)
		exit_free_error(data, MSG_MAP_NEWLINE);
	else if (line[0] != '\n')
		exit_free_error(data, MSG_SYNTAX_ERROR);
}

static char	*remove_map_spaces(char *line)
{
	char	*final;
	char	*temp;

	temp = ft_strtrim(line, " ");
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

void	parse_map(t_data *data, char *file)
{
	char	*line;
	char	*temp;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_error(MSG_OPEN_FAILED);
	initialize_map_table(data);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp = remove_map_spaces(line);
		free(line);
		retrieve_map_infos(data, temp);
		free(temp);
	}
	data->map.array = ft_split(data->map.str, '\n');
	print_map_infos(data);
	check_is_valid_map(data);
}
