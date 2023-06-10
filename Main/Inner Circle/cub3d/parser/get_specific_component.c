/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_specific_component.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:00:51 by haryu             #+#    #+#             */
/*   Updated: 2022/11/13 14:22:39 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*get_specific_component(t_mapcontents *map, char *temp, int code)
{
	size_t	length;
	char	*ret;

	if (map->filed[code] != 0)
		ft_error(INVALID_IDENTIFIER);
	length = 0;
	while (temp[length] != '\n')
		length++;
	ret = ft_strndup(temp, length + 2);
	ret[length + 1] = '\0';
	map->filed[code] = ft_strlen(ret);
	return (ret);
}
