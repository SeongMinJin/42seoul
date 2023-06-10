/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_components.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:02:04 by haryu             #+#    #+#             */
/*   Updated: 2022/11/13 14:21:45 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	get_map_components(t_mapcontents *map, char *file_data, \
int *index, char *keyword)
{
	char	*temp;

	temp = ft_strstr(file_data + *index, keyword);
	if (!ft_strcmp(keyword, "NO"))
		map->no = get_specific_component(map, temp, 0);
	else if (!ft_strcmp(keyword, "SO"))
		map->so = get_specific_component(map, temp, 1);
	else if (!ft_strcmp(keyword, "WE"))
		map->we = get_specific_component(map, temp, 2);
	else if (!ft_strcmp(keyword, "EA"))
		map->ea = get_specific_component(map, temp, 3);
	else if (!ft_strcmp(keyword, "F"))
		map->f = get_specific_component(map, temp, 4);
	else if (!ft_strcmp(keyword, "C"))
		map->c = get_specific_component(map, temp, 5);
	while (file_data[*index] != '\n')
		*index += 1;
}
