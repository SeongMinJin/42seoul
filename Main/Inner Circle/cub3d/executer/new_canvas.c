/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_canvas.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:55:36 by seojin            #+#    #+#             */
/*   Updated: 2022/11/13 14:56:44 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_canvas	*new_canvas(void)
{
	t_canvas	*canvas;

	canvas = (t_canvas *)malloc(sizeof(t_canvas));
	if (!canvas)
		ft_error(MALLOC_ERR);
	canvas->img = NULL;
	canvas->addr = NULL;
	canvas->bits_per_pixel = 0;
	canvas->line_length = 0;
	canvas->endian = 0;
	return (canvas);
}
