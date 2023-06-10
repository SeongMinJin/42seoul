/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reorder_map_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 00:10:39 by haryu             #+#    #+#             */
/*   Updated: 2022/11/14 14:33:28 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*reorder_map_data(char *file_data)
{
	t_mapcontents	temp;
	int				i;

	i = -1;
	init_mapcomponents(&temp);
	while (file_data[++i])
	{
		if (file_data[i] == 'N' && file_data[i + 1] == 'O')
			get_map_components(&temp, file_data, &i, "NO");
		else if (file_data[i] == 'S' && file_data[i + 1] == 'O')
			get_map_components(&temp, file_data, &i, "SO");
		else if (file_data[i] == 'W' && file_data[i + 1] == 'E')
			get_map_components(&temp, file_data, &i, "WE");
		else if (file_data[i] == 'E' && file_data[i + 1] == 'A')
			get_map_components(&temp, file_data, &i, "EA");
		else if (file_data[i] == 'F')
			get_map_components(&temp, file_data, &i, "F");
		else if (file_data[i] == 'C')
			get_map_components(&temp, file_data, &i, "C");
		if (check_map_flag(&temp))
			break ;
	}
	return (reorder_map_components(&temp, file_data, i));
}
