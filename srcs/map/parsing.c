/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:49:12 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/20 19:00:52 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*allocate_map_infos(char *line, int start)
{
	char	*final;
	int		new_line;
	int		len;

	new_line = 0;
	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		new_line = 1;
	final = ft_substr(line, start, (len - start) - new_line);
	return (final);
}

static void	retrieve_map_infos(t_data *data, char *line)
{
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
	else if (line[0] == '1' || line[0] == '0' || ft_iswhitespace(line[0]))
		data->map.str = ft_strjoin(data->map.str, line);
}

void	parse_map(t_data *data, char *file)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_error(MSG_OPEN_FAILED);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		retrieve_map_infos(data, line);
		free(line);
	}
	data->map.array = ft_split(data->map.str, '\n');
	print_map_infos(data);
}