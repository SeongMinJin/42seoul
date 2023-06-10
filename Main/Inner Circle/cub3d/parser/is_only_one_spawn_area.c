/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_only_one_spawn_area.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:56:05 by seojin            #+#    #+#             */
/*   Updated: 2022/11/13 14:56:41 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	set_start_point(t_map *map, \
int orientaiton, int x, int y);

void	is_only_one_spawn_area(t_map *map)
{
	int	x;
	int	y;
	int	is_spawn;
	int	**int_map;

	y = 0;
	int_map = map->map;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			is_spawn = is_spawn_area(int_map[y][x]);
			if (map->spawn_orientation && is_spawn)
				ft_error(MULTIPLE_SPAWN);
			else if (is_spawn)
				set_start_point(map, int_map[y][x], x, y);
			++x;
		}
		++y;
	}
	if (!map->spawn_orientation)
		ft_error(NO_SPAWN_AREA);
}

static void	set_start_point(t_map *map, int orientaiton, int x, int y)
{
	map->spawn_orientation = orientaiton;
	map->spawn_x = x;
	map->spawn_y = y;
}
