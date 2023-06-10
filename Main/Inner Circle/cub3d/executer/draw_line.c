/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:55:28 by seojin            #+#    #+#             */
/*   Updated: 2022/11/14 17:21:56 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static t_texture	*which_texture(t_cub3d *cub3d);
static void			init_dummy(t_cub3d *cub3d, t_dummy *dummy);
static void			get_start_end(double perp_d, \
int *height, int *start, int *end);

void	draw_line(t_cub3d *cub3d, int x)
{
	int				y;
	int				tex_y;
	unsigned int	color;
	t_dummy			*dummy;

	dummy = malloc(sizeof(t_dummy));
	if (!dummy)
		ft_error(MALLOC_ERR);
	get_start_end(cub3d->perp_d, &dummy->height, &dummy->start, &dummy->end);
	dummy->texture = which_texture(cub3d);
	init_dummy(cub3d, dummy);
	y = dummy->start;
	while (y < dummy->end)
	{
		tex_y = (int)dummy->tex_y_pos;
		dummy->tex_y_pos += dummy->step;
		color = *(unsigned int *)(dummy->texture->addr + \
		dummy->texture->line_length * tex_y + dummy->tex_x * 4);
		put_pixel(cub3d->canvas, x, y, color);
		y++;
	}
	free(dummy);
}

static void	init_dummy(t_cub3d *cub3d, t_dummy *dummy)
{
	double	wall;

	if (cub3d->side)
		wall = cub3d->user->curr_x + cub3d->perp_d * cub3d->raydir_x;
	else
		wall = cub3d->user->curr_y + cub3d->perp_d * cub3d->raydir_y;
	wall -= floor(wall);
	dummy->tex_x = (int)(wall * dummy->texture->width);
	dummy->step = (double)dummy->texture->height / (double)dummy->height;
	dummy->tex_y_pos = (dummy->start - HEIGHT / 2 + \
	dummy->height / 2) * dummy->step;
}

static void	get_start_end(double perp_d, int *height, int *start, int *end)
{
	*height = (int)(HEIGHT / perp_d);
	*start = -(*height) / 2 + HEIGHT / 2;
	if (*start < 0)
		*start = 0;
	*end = *height / 2 + HEIGHT / 2;
	if (*end >= HEIGHT)
		*end = HEIGHT - 1;
}

static t_texture	*which_texture(t_cub3d *cub3d)
{
	if (cub3d->side)
	{
		if (cub3d->raydir_y < 0)
			return (cub3d->s_texture);
		else
			return (cub3d->n_texture);
	}
	else
	{
		if (cub3d->raydir_x < 0)
			return (cub3d->e_texture);
		else
			return (cub3d->w_texture);
	}
}
