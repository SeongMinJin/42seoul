/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall_texture_info.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:55:59 by seojin            #+#    #+#             */
/*   Updated: 2022/11/13 14:56:42 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	get_no_info(t_map *map, char *file_data);
static void	get_so_info(t_map *map, char *file_data);
static void	get_we_info(t_map *map, char *file_data);
static void	get_ea_info(t_map *map, char *file_data);

void	get_wall_texture_info(t_map *map, char **file_data)
{
	get_no_info(map, file_data[0]);
	get_so_info(map, file_data[1]);
	get_we_info(map, file_data[2]);
	get_ea_info(map, file_data[3]);
	verify_xpm_extension(file_data[0]);
	verify_xpm_extension(file_data[1]);
	verify_xpm_extension(file_data[2]);
	verify_xpm_extension(file_data[3]);
}

static void	get_no_info(t_map *map, char *file_data)
{
	int		fd;
	char	*tmp;

	tmp = ft_strstr(file_data, "NO");
	tmp += 2;
	while (*tmp == ' ')
		tmp++;
	fd = open(tmp, O_RDONLY);
	if (fd < 0)
		ft_error(NO_SUCH_FILE);
	close(fd);
	map->n_texture = ft_strdup(tmp);
}

static void	get_so_info(t_map *map, char *file_data)
{
	int		fd;
	char	*tmp;

	tmp = ft_strstr(file_data, "SO");
	tmp += 2;
	while (*tmp == ' ')
		tmp++;
	fd = open(tmp, O_RDONLY);
	if (fd < 0)
		ft_error(NO_SUCH_FILE);
	close(fd);
	map->s_texture = ft_strdup(tmp);
}

static void	get_we_info(t_map *map, char *file_data)
{
	int		fd;
	char	*tmp;

	tmp = ft_strstr(file_data, "WE");
	tmp += 2;
	while (*tmp == ' ')
		tmp++;
	fd = open(tmp, O_RDONLY);
	if (fd < 0)
		ft_error(NO_SUCH_FILE);
	close(fd);
	map->w_texture = ft_strdup(tmp);
}

static void	get_ea_info(t_map *map, char *file_data)
{
	int		fd;
	char	*tmp;

	tmp = ft_strstr(file_data, "EA");
	tmp += 2;
	while (*tmp == ' ')
		tmp++;
	fd = open(tmp, O_RDONLY);
	if (fd < 0)
		ft_error(NO_SUCH_FILE);
	close(fd);
	map->e_texture = ft_strdup(tmp);
}
