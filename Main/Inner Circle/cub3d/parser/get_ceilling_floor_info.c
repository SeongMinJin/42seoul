/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ceilling_floor_info.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:55:52 by seojin            #+#    #+#             */
/*   Updated: 2022/11/13 14:56:42 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	get_floor_info(t_map *map, char **file_data);
static void	get_ceilling_info(t_map *map, char **file_data);
static int	rgb_to_int(char *rgb);
static int	bit_to_int(int bit);

void	get_ceilling_floor_info(t_map *map, char **file_data)
{
	get_floor_info(map, file_data);
	get_ceilling_info(map, file_data);
}

static void	get_floor_info(t_map *map, char **file_data)
{
	char	*tmp;

	tmp = ft_strstr(file_data[4], "F");
	++tmp;
	while (*tmp == ' ')
		tmp++;
	map->floor_color = rgb_to_int(tmp);
}

static void	get_ceilling_info(t_map *map, char **file_data)
{
	char	*tmp;

	tmp = ft_strstr(file_data[5], "C");
	++tmp;
	while (*tmp == ' ')
		tmp++;
	map->ceilling_color = rgb_to_int(tmp);
}

static int	rgb_to_int(char *rgb)
{
	char	**tmp;
	int		red;
	int		green;
	int		blue;

	tmp = ft_split(rgb, ',');
	if (ft_strlen_2d(tmp) != 3)
		ft_error(INVALID_RGB);
	red = bit_to_int(ft_atoi(tmp[0])) << 16;
	green = bit_to_int(ft_atoi(tmp[1])) << 8;
	blue = bit_to_int(ft_atoi(tmp[2]));
	ft_free_str_2d(tmp);
	return (red + green + blue);
}

static int	bit_to_int(int bit)
{
	int	num;

	num = 0;
	if (bit & 128)
		num += 128;
	if (bit & 64)
		num += 64;
	if (bit & 32)
		num += 32;
	if (bit & 16)
		num += 16;
	if (bit & 8)
		num += 8;
	if (bit & 4)
		num += 4;
	if (bit & 2)
		num += 2;
	if (bit & 1)
		num += 1;
	return (num);
}
