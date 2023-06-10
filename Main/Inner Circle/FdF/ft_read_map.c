/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:38:31 by seojin            #+#    #+#             */
/*   Updated: 2022/10/03 14:30:34 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	*ft_str_to_int(char *str_map, int len)
{
	int	*arr;
	int	i;

	arr = (int *)malloc(len * sizeof(int));
	if (!arr)
		return (0);
	i = 0;
	while (i < len)
	{
		*(arr + i) = ft_atoi(str_map);
		i++;
		while (*str_map && *str_map != ' ')
			str_map++;
		while (*str_map && *str_map == ' ')
			str_map++;
	}
	return (arr);
}

static int	**ft_get_int_map(char **str_map, int width, int height)
{
	int	**int_map;
	int	i;

	int_map = (int **)malloc(height * sizeof(int *));
	if (!int_map)
	{
		ft_free_str_map(str_map);
		ft_exit(MALLOC_ERROR);
	}
	i = 0;
	while (i < height)
	{
		*(int_map + i) = ft_str_to_int(*(str_map + i), width);
		if (!*(int_map + i))
		{
			ft_free_str_map(str_map);
			ft_free_int_map(int_map, i);
			ft_exit(MALLOC_ERROR);
		}
		i++;
	}
	return (int_map);
}

static char	*ft_get_str_map(char *map_file, size_t byte)
{
	char	*map;
	int		fd;

	map = (char *)malloc((byte + 1) * sizeof(char));
	if (!map)
		ft_exit(MALLOC_ERROR);
	*(map + byte) = 0;
	fd = open(map_file, O_RDONLY);
	read(fd, map, byte);
	close(fd);
	return (map);
}

static size_t	ft_get_byte(char *map_file)
{
	char	buf[1];
	int		fd;
	size_t	byte;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		ft_exit(OPEN_ERROR);
	byte = 0;
	while (read(fd, buf, 1))
		byte++;
	close(fd);
	return (byte);
}

t_map	ft_read_map(char *map_file)
{
	t_map	map;

	map.temp_map = ft_get_str_map(map_file, ft_get_byte(map_file));
	ft_get_byte(map_file);
	map.str_map = ft_split(map.temp_map, '\n');
	map.width = ft_get_width(*(map.str_map));
	map.height = ft_get_height(map.str_map);
	map.int_map = ft_get_int_map(map.str_map, map.width, map.height);
	map.scale = 5;
	map.degree = 30;
	map.benchmark_x = WIDTH / 2;
	map.benchmark_y = HEIGHT / 2;
	free(map.temp_map);
	map.temp_map = 0;
	ft_free_str_map(map.str_map);
	map.str_map = 0;
	return (map);
}
