/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:35:18 by seojin            #+#    #+#             */
/*   Updated: 2022/08/18 19:08:18 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_get_height(char **map)
{
	char	**s;

	s = map;
	while (*s)
		s++;
	return (s - map);
}

int	ft_get_width(char *map)
{
	int	width;

	width = 0;
	while (*map)
	{
		while (*map && *map != ' ')
			map++;
		width++;
		if (*map)
		{
			while (*map == ' ')
				map++;
		}
	}
	return (width);
}
