/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:55:56 by seojin            #+#    #+#             */
/*   Updated: 2022/11/13 14:56:42 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	get_map(t_map *map, char *file_data)
{
	char	**splited_file_data;

	splited_file_data = ft_split(file_data, '\n');
	get_wall_texture_info(map, splited_file_data);
	get_ceilling_floor_info(map, splited_file_data);
	get_int_map(map, splited_file_data);
	ft_free_str_2d(splited_file_data);
}
