/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:55:29 by seojin            #+#    #+#             */
/*   Updated: 2022/11/13 14:56:45 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	execute(t_map *map)
{
	t_cub3d	*cub3d;

	cub3d = init_cub3d(map);
	cast_ray(cub3d);
	mlx_hook(cub3d->mlx_win, 2, 1, key_handler, cub3d);
	mlx_hook(cub3d->mlx_win, 17, 1, expose, cub3d);
	mlx_loop(cub3d->mlx);
}
