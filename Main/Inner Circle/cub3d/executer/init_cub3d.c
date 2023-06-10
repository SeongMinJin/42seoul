/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:55:31 by seojin            #+#    #+#             */
/*   Updated: 2022/11/14 17:27:26 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_cub3d	*init_cub3d(t_map *map)
{
	t_cub3d	*cub3d;

	cub3d = (t_cub3d *)malloc(sizeof(t_cub3d));
	if (!cub3d)
		ft_error(MALLOC_ERR);
	cub3d->mlx = mlx_init();
	cub3d->mlx_win = mlx_new_window(cub3d->mlx, WIDTH, HEIGHT, "cub3D");
	cub3d->canvas = new_canvas();
	init_img(cub3d->mlx, cub3d->canvas);
	cub3d->map = map;
	cub3d->user = new_user(map);
	init_texture(cub3d);
	cub3d->map_x = cub3d->map->spawn_x;
	cub3d->map_y = cub3d->map->spawn_y;
	cub3d->step_x = 0;
	cub3d->step_y = 0;
	cub3d->side = 0;
	cub3d->raydir_x = 0;
	cub3d->raydir_y = 0;
	cub3d->d_x = 0;
	cub3d->d_y = 0;
	cub3d->perp_d = 0;
	return (cub3d);
}
