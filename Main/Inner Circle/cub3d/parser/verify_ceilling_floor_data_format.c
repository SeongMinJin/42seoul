/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_ceilling_floor_data_format.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:56:17 by seojin            #+#    #+#             */
/*   Updated: 2022/11/13 14:56:37 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*verify_ceilling_floor_data_format(char *file_data)
{
	while (ft_isspace(*file_data))
		++file_data;
	if (!ft_strnstr(file_data, "F", 1))
		ft_error(INVALID_IDENTIFIER);
	while (*file_data != '\n')
		++file_data;
	while (ft_isspace(*file_data))
		++file_data;
	if (!ft_strnstr(file_data, "C", 1))
		ft_error(INVALID_IDENTIFIER);
	while (*file_data != '\n')
		++file_data;
	return (file_data);
}
