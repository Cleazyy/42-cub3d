/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:49:12 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/06 09:15:13 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	initialize_map_table(t_data *data)
{
	data->map.str = NULL;
	data->map.array = NULL;
	data->map.sprite.no_path = NULL;
	data->map.sprite.so_path = NULL;
	data->map.sprite.we_path = NULL;
	data->map.sprite.ea_path = NULL;
	data->map.floor_color = NULL;
	data->map.ceiling_color = NULL;
}

static char	*allocate_map_infos(char *line, int start)
{
	char	*final;
	char	*temp;
	int		new_line;
	int		len;

	new_line = 0;
	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		new_line = 1;
	temp = ft_substr(line, start, (len - start) - new_line);
	final = ft_strtrim(temp, " ");
	free(temp);
	return (final);
}

static void	retrieve_map_infos(t_data *data, char *line)
{
	char	*temp;

	if (line[0] == 'N' && line[1] == 'O')
		data->map.sprite.no_path = allocate_map_infos(line, 3);
	else if (line[0] == 'S' && line[1] == 'O')
		data->map.sprite.so_path = allocate_map_infos(line, 3);
	else if (line[0] == 'W' && line[1] == 'E')
		data->map.sprite.we_path = allocate_map_infos(line, 3);
	else if (line[0] == 'E' && line[1] == 'A')
		data->map.sprite.ea_path = allocate_map_infos(line, 3);
	else if (line[0] == 'F')
		data->map.floor_color = allocate_map_infos(line, 2);
	else if (line[0] == 'C')
		data->map.ceiling_color = allocate_map_infos(line, 2);
	else if (line[0] == '1' || line[0] == '0' || line[0] == ' ')
	{
		temp = ft_strdup(data->map.str);
		free(data->map.str);
		data->map.str = ft_strjoin(temp, line);
		free(temp);
	}
	else if (line[0] != '\n')
		exit_free_error(data, "Map syntax error!");
}

void	parse_map(t_data *data, char *file)
{
	char	*line;
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
		// char *temp = ft_strtrim(line, " ");
		// free(line);
		// line = temp;
		retrieve_map_infos(data, line);
		free(line);
	}
	data->map.array = ft_split(data->map.str, '\n');
	print_map_infos(data);
	check_is_valid_map(data);
}
