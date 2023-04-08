/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:34:54 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/08 12:20:58 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_args(int ac, char **av)
{
	char	*map;
	int		len;

	if (ac != 2)
		return (print_error(MSG_WRONG_NB_ARGS));
	map = av[1];
	len = ft_strlen(map);
	if (len < 5 || ft_strncmp(map + (len - 4), ".cub", 4))
		return (print_error(MSG_INVALID_MAP));
	return (0);
}
