/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:56:11 by seojin            #+#    #+#             */
/*   Updated: 2022/11/13 14:56:40 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static t_map	*new_map(void);

t_map	*parse_map(char *file_name)
{
	char	*file_data;
	t_map	*map;

	verify_cub_extension(file_name);
	file_data = read_file(file_name);
	file_data = verify_file_format(file_data);
	map = new_map();
	get_map(map, file_data);
	is_only_one_spawn_area(map);
	is_closed_map(map);
	free(file_data);
	return (map);
}

static t_map	*new_map(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		ft_error(MALLOC_ERR);
	map->n_texture = NULL;
	map->s_texture = NULL;
	map->w_texture = NULL;
	map->e_texture = NULL;
	map->ceilling_color = 0;
	map->floor_color = 0;
	map->map = NULL;
	map->width = 0;
	map->height = 0;
	map->spawn_x = 0;
	map->spawn_y = 0;
	map->spawn_orientation = 0;
	return (map);
}
