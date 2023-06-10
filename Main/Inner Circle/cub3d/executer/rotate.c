/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:55:41 by seojin            #+#    #+#             */
/*   Updated: 2022/11/13 14:56:43 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	rotate_right(t_cub3d *cub3d)
{
	double	rad;
	double	dir_x;
	double	dir_y;

	rad = ft_deg_to_rad(-5);
	dir_x = cub3d->user->dir_x;
	dir_y = cub3d->user->dir_y;
	cub3d->user->dir_x = dir_x * cos(rad) + dir_y * sin(rad);
	cub3d->user->dir_y = -dir_x * sin(rad) + dir_y * cos(rad);
	dir_x = cub3d->user->plane_x;
	dir_y = cub3d->user->plane_y;
	cub3d->user->plane_x = dir_x * cos(rad) + dir_y * sin(rad);
	cub3d->user->plane_y = -dir_x * sin(rad) + dir_y * cos(rad);
	mlx_destroy_image(cub3d->mlx, cub3d->canvas->img);
	init_img(cub3d->mlx, cub3d->canvas);
	cast_ray(cub3d);
}

void	rotate_left(t_cub3d *cub3d)
{
	double	rad;
	double	dir_x;
	double	dir_y;

	rad = ft_deg_to_rad(5);
	dir_x = cub3d->user->dir_x;
	dir_y = cub3d->user->dir_y;
	cub3d->user->dir_x = dir_x * cos(rad) + dir_y * sin(rad);
	cub3d->user->dir_y = -dir_x * sin(rad) + dir_y * cos(rad);
	dir_x = cub3d->user->plane_x;
	dir_y = cub3d->user->plane_y;
	cub3d->user->plane_x = dir_x * cos(rad) + dir_y * sin(rad);
	cub3d->user->plane_y = -dir_x * sin(rad) + dir_y * cos(rad);
	mlx_destroy_image(cub3d->mlx, cub3d->canvas->img);
	init_img(cub3d->mlx, cub3d->canvas);
	cast_ray(cub3d);
}
