/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:55:27 by seojin            #+#    #+#             */
/*   Updated: 2022/11/14 12:34:17 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	get_step_side_info(t_cub3d *cub3d);
static void	is_hit(t_cub3d *cub3d);
static void	get_perp_distance(t_cub3d *cub3d);
static void	paint_ceil_floor(t_cub3d *cub3d);

void	cast_ray(t_cub3d *cub3d)
{
	int		x;

	x = 0;
	paint_ceil_floor(cub3d);
	while (x < WIDTH)
	{
		cub3d->raydir_x = cub3d->user->dir_x + \
		(2.0 * x / 1080.0 - 1) * cub3d->user->plane_x;
		cub3d->raydir_y = cub3d->user->dir_y + \
		(2.0 * x / 1080.0 - 1) * cub3d->user->plane_y;
		cub3d->d_x = fabs(hypot(cub3d->raydir_x, cub3d->raydir_y) \
		/ cub3d->raydir_x);
		cub3d->d_y = fabs(hypot(cub3d->raydir_x, cub3d->raydir_y) \
		/ cub3d->raydir_y);
		get_step_side_info(cub3d);
		is_hit(cub3d);
		get_perp_distance(cub3d);
		draw_line(cub3d, x);
		cub3d->map_x = (int)cub3d->user->curr_x;
		cub3d->map_y = (int)cub3d->user->curr_y;
		x++;
	}
	mlx_put_image_to_window(cub3d->mlx, \
	cub3d->mlx_win, cub3d->canvas->img, 0, 0);
}

static void	paint_ceil_floor(t_cub3d *cub3d)
{
	int		idx;
	int		range;
	char	*point;

	idx = 0;
	range = WIDTH * (HEIGHT / 2);
	point = cub3d->canvas->addr;
	while (idx < range)
	{
		if (!*(unsigned int *)point)
			*(unsigned int *)point = cub3d->map->ceilling_color;
		idx++;
		point += 4;
	}
	idx = 0;
	range = WIDTH * (HEIGHT / 2);
	point = cub3d->canvas->addr + WIDTH * HEIGHT / 2 * 4;
	while (idx < range)
	{
		if (!*(unsigned int *)point)
			*(unsigned int *)point = cub3d->map->floor_color;
		idx++;
		point += 4;
	}
}

static void	get_perp_distance(t_cub3d *cub3d)
{
	if (cub3d->side)
		cub3d->perp_d = (cub3d->map_y - cub3d->user->curr_y + \
		(1 - cub3d->step_y) / 2) / cub3d->raydir_y;
	else
		cub3d->perp_d = (cub3d->map_x - cub3d->user->curr_x + \
		(1 - cub3d->step_x) / 2) / cub3d->raydir_x;
}

static void	is_hit(t_cub3d *cub3d)
{
	while (1)
	{
		if (cub3d->side_x < cub3d->side_y)
		{
			cub3d->side_x += cub3d->d_x;
			cub3d->map_x += cub3d->step_x;
			cub3d->side = 0;
		}
		else
		{
			cub3d->side_y += cub3d->d_y;
			cub3d->map_y += cub3d->step_y;
			cub3d->side = 1;
		}
		if (cub3d->map->map[cub3d->map_y][cub3d->map_x] == WALL)
			return ;
	}
}

static void	get_step_side_info(t_cub3d *cub3d)
{
	if (cub3d->raydir_x < 0)
	{
		cub3d->step_x = -1;
		cub3d->side_x = (cub3d->user->curr_x - cub3d->map_x) * cub3d->d_x;
	}
	else
	{
		cub3d->step_x = 1;
		cub3d->side_x = (cub3d->map_x + 1 - cub3d->user->curr_x) * cub3d->d_x;
	}
	if (cub3d->raydir_y < 0)
	{
		cub3d->step_y = -1;
		cub3d->side_y = (cub3d->user->curr_y - cub3d->map_y) * cub3d->d_y;
	}
	else
	{
		cub3d->step_y = 1;
		cub3d->side_y = (cub3d->map_y + 1 - cub3d->user->curr_y) * cub3d->d_y;
	}
}
