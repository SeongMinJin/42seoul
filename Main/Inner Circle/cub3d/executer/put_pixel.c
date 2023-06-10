/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:55:40 by seojin            #+#    #+#             */
/*   Updated: 2022/11/13 14:56:43 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	put_pixel(t_canvas *canvas, int x, int y, unsigned int color)
{
	char	*point;

	point = canvas->addr + (y * canvas->line_length + \
	x * (canvas->bits_per_pixel / 8));
	*(unsigned int *)point = color;
}
