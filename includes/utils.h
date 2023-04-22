/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:58:35 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/22 17:00:59 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/* errors */
int		print_error(char *str);
void	exit_error(char *str);
void	exit_free_error(t_data *data, char *str);
/* free */
void	free_array(char **array);
void	free_everythings(t_data *data);

#endif
