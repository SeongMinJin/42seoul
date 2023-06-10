/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map_data_format.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:56:24 by seojin            #+#    #+#             */
/*   Updated: 2022/11/13 14:56:35 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	verify_map_data_format(char *file_data)
{
	int	len;

	while (*file_data == '\n')
		++file_data;
	if (!*file_data)
		ft_error(INVALID_MAP);
	while (*file_data)
	{
		len = 0;
		while (*file_data && *file_data != '\n')
		{
			if (!is_map_content(*file_data))
				ft_error(INVALID_MAP);
			++file_data;
			++len;
		}
		if (*file_data)
			++file_data;
		if (len == 0)
			break ;
	}
	while (*file_data++)
		if (*file_data != '\n')
			ft_error(INVALID_MAP);
}
