/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int_map_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:55:54 by seojin            #+#    #+#             */
/*   Updated: 2022/11/13 14:56:42 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	get_map_width_height(t_map *map, char **file_data);
static int	*get_int_map_line(int width, char *str_line);

void	get_int_map(t_map *map, char **file_data)
{
	int	idx;
	int	**int_map;

	get_map_width_height(map, file_data);
	int_map = (int **)malloc(map->height * sizeof(int *));
	if (!int_map)
		ft_error(MALLOC_ERR);
	idx = 6;
	while (file_data[idx])
	{
		int_map[idx - 6] = get_int_map_line(map->width, file_data[idx]);
		++idx;
	}
	map->map = int_map;
}

static int	*get_int_map_line(int width, char *str_line)
{
	int	idx;
	int	*int_line;

	int_line = (int *)malloc(width * sizeof(int));
	if (!int_line)
		ft_error(MALLOC_ERR);
	idx = 0;
	while (str_line[idx] && width)
	{
		int_line[idx] = str_line[idx];
		++idx;
		--width;
	}
	while (width)
	{
		int_line[idx] = NONE;
		++idx;
		--width;
	}
	return (int_line);
}

static void	get_map_width_height(t_map *map, char **file_data)
{
	int	idx;
	int	str_len;
	int	width;
	int	height;

	idx = 6;
	width = 0;
	height = 0;
	while (file_data[idx])
	{
		str_len = ft_strlen(file_data[idx]);
		if (str_len > width)
			width = str_len;
		++idx;
		++height;
	}
	map->width = width;
	map->height = height;
}
