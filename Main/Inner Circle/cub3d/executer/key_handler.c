/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:55:34 by seojin            #+#    #+#             */
/*   Updated: 2022/11/14 17:37:11 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	key_handler(int keycode, t_cub3d *cub3d)
{
	if (keycode == ESC)
		exit(0);
	else if (keycode == W)
		move_forward(cub3d);
	else if (keycode == A)
		move_left(cub3d);
	else if (keycode == S)
		move_backward(cub3d);
	else if (keycode == D)
		move_right(cub3d);
	else if (keycode == LEFT)
		rotate_left(cub3d);
	else if (keycode == RIGHT)
		rotate_right(cub3d);
	return (0);
}
