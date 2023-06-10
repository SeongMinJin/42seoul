/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:55:35 by seojin            #+#    #+#             */
/*   Updated: 2022/11/13 14:56:44 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	move_forward(t_cub3d *cub3d)
{
	double	dir_x;
	double	dir_y;
	t_user	*user;

	user = cub3d->user;
	dir_x = user->dir_x / 5.0;
	dir_y = user->dir_y / 5.0;
	if (cub3d->map->map[(int)(user->curr_y + dir_y)] \
	[(int)(user->curr_x + dir_x)] == WALL)
		return ;
	user->curr_x += dir_x;
	user->curr_y += dir_y;
	mlx_destroy_image(cub3d->mlx, cub3d->canvas->img);
	init_img(cub3d->mlx, cub3d->canvas);
	cast_ray(cub3d);
}

void	move_left(t_cub3d *cub3d)
{
	double	rad;
	double	dir_x;
	double	dir_y;
	t_user	*user;

	user = cub3d->user;
	rad = ft_deg_to_rad(90);
	dir_x = (user->dir_x * cos(rad) + user->dir_y * sin(rad)) / 5;
	dir_y = (-user->dir_x * sin(rad) + user->dir_y * cos(rad)) / 5;
	if (cub3d->map->map[(int)(user->curr_y + dir_y)] \
	[(int)(user->curr_x + dir_x)] == WALL)
		return ;
	user->curr_x += dir_x;
	user->curr_y += dir_y;
	mlx_destroy_image(cub3d->mlx, cub3d->canvas->img);
	init_img(cub3d->mlx, cub3d->canvas);
	cast_ray(cub3d);
}

void	move_backward(t_cub3d *cub3d)
{
	double	rad;
	double	dir_x;
	double	dir_y;
	t_user	*user;

	user = cub3d->user;
	rad = ft_deg_to_rad(180);
	dir_x = (user->dir_x * cos(rad) + user->dir_y * sin(rad)) / 5;
	dir_y = (-user->dir_x * sin(rad) + user->dir_y * cos(rad)) / 5;
	if (cub3d->map->map[(int)(user->curr_y + dir_y)] \
	[(int)(user->curr_x + dir_x)] == WALL)
		return ;
	user->curr_x += dir_x;
	user->curr_y += dir_y;
	mlx_destroy_image(cub3d->mlx, cub3d->canvas->img);
	init_img(cub3d->mlx, cub3d->canvas);
	cast_ray(cub3d);
}

void	move_right(t_cub3d *cub3d)
{
	double	rad;
	double	dir_x;
	double	dir_y;
	t_user	*user;

	user = cub3d->user;
	rad = ft_deg_to_rad(-90);
	dir_x = (user->dir_x * cos(rad) + user->dir_y * sin(rad)) / 5;
	dir_y = (-user->dir_x * sin(rad) + user->dir_y * cos(rad)) / 5;
	if (cub3d->map->map[(int)(user->curr_y + dir_y)] \
	[(int)(user->curr_x + dir_x)] == WALL)
		return ;
	user->curr_x += dir_x;
	user->curr_y += dir_y;
	mlx_destroy_image(cub3d->mlx, cub3d->canvas->img);
	init_img(cub3d->mlx, cub3d->canvas);
	cast_ray(cub3d);
}
