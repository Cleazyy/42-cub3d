/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:34:13 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/19 15:34:33 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	print_error(char *str)
{
	ft_putendl_fd(MSG_ERROR, STDERR_FILENO);
	ft_putendl_fd(str, STDERR_FILENO);
	return (0);
}
