/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:55:32 by seojin            #+#    #+#             */
/*   Updated: 2022/11/13 14:56:44 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_img(void *mlx, t_canvas *canvas)
{
	canvas->img = mlx_new_image(mlx, WIDTH, HEIGHT);
	canvas->addr = mlx_get_data_addr(canvas->img, \
	&canvas->bits_per_pixel, &canvas->line_length, \
	&canvas->endian);
}
