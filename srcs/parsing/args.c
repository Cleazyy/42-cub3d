/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:24:57 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/10 14:28:50 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_args_nb(int ac)
{
	if (ac != 2)
		return (1);
	return (0);
}

int	check_map_name(char **av)
{
	char	*map;
	int		len;

	map = av[1];
	len = ft_strlen(av[1]);
	if (len < 5 || ft_strncmp(map + (len - 4), ".cub", 4))
		return (1);
	return (0);
}
