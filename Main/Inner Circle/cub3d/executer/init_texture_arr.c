/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture_arr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:55:33 by seojin            #+#    #+#             */
/*   Updated: 2022/11/14 17:21:53 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static t_texture	*new_texture(void *mlx, char *file);

void	init_texture(t_cub3d *cub3d)
{
	cub3d->n_texture = new_texture(cub3d->mlx, cub3d->map->n_texture);
	cub3d->s_texture = new_texture(cub3d->mlx, cub3d->map->s_texture);
	cub3d->w_texture = new_texture(cub3d->mlx, cub3d->map->w_texture);
	cub3d->e_texture = new_texture(cub3d->mlx, cub3d->map->e_texture);
}

static t_texture	*new_texture(void *mlx, char *file)
{
	t_texture	*texture;

	texture = (t_texture *)malloc(sizeof(t_texture));
	if (!texture)
		ft_error(MALLOC_ERR);
	texture->img = mlx_xpm_file_to_image(mlx, file, \
	&texture->width, &texture->height);
	if (!texture->img)
		ft_error(XPM_FILE_ERR);
	texture->addr = mlx_get_data_addr(texture->img, &texture->bits_per_pixel, \
	&texture->line_length, &texture->endian);
	return (texture);
}
