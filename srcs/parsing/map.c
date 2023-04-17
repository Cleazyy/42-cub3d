/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 21:35:57 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/17 07:20:47 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*allocate_info(t_data *data, char *line, int start, int info)
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

void	parse_map(t_data *data, char *line)
{
	static int	is_map = 0;

	if (ft_strncmp("NO ", line, 3) == 0)
		data->map.sprite.no_path = allocate_info(data, line, 3, 1);
	else if (ft_strncmp("SO ", line, 3) == 0)
		data->map.sprite.so_path = allocate_info(data, line, 3, 2);
	else if (ft_strncmp("WE ", line, 3) == 0)
		data->map.sprite.we_path = allocate_info(data, line, 3, 3);
	else if (ft_strncmp("EA ", line, 3) == 0)
		data->map.sprite.ea_path = allocate_info(data, line, 3, 4);
	else if (ft_strncmp("F ", line, 2) == 0)
		data->map.floor_color = allocate_info(data, line, 2, 5);
	else if (ft_strncmp("C ", line, 2) == 0)
		data->map.ceiling_color = allocate_info(data, line, 2, 6);
	else if (line[0] == '1' || line[0] == '0' || line[0] == ' ')
	{
		is_map = 1;
		allocate_map(data, line);
	}
	else if (line[0] == '\n' && is_map == 1)
		exit_free_error(data, MSG_MAP_NEWLINE);
	else if (line[0] != '\n')
		exit_free_error(data, MSG_SYNTAX_ERROR);
}
