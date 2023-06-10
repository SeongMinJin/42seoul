/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_closed_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:56:02 by seojin            #+#    #+#             */
/*   Updated: 2022/11/13 14:56:42 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	check_around(t_map *map, int x, int y);

void	is_closed_map(t_map *map)
{
	int	x;
	int	y;
	int	**int_map;

	y = 0;
	int_map = map->map;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (is_spawn_area(int_map[y][x]) || int_map[y][x] == EMPTY_SPACE)
				check_around(map, x, y);
			++x;
		}
		++y;
	}
}

static void	check_around(t_map *map, int x, int y)
{
	int	**int_map;

	int_map = map->map;
	if (x == 0 || x == map->width - 1 || \
	y == 0 || y == map->height - 1)
		ft_error(INVALID_MAP);
	else if (int_map[y - 1][x - 1] == NONE)
		ft_error(INVALID_MAP);
	else if (int_map[y - 1][x] == NONE)
		ft_error(INVALID_MAP);
	else if (int_map[y - 1][x + 1] == NONE)
		ft_error(INVALID_MAP);
	else if (int_map[y][x - 1] == NONE)
		ft_error(INVALID_MAP);
	else if (int_map[y][x + 1] == NONE)
		ft_error(INVALID_MAP);
	else if (int_map[y + 1][x - 1] == NONE)
		ft_error(INVALID_MAP);
	else if (int_map[y + 1][x] == NONE)
		ft_error(INVALID_MAP);
	else if (int_map[y + 1][x + 1] == NONE)
		ft_error(INVALID_MAP);
}
