/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:11:37 by seojin            #+#    #+#             */
/*   Updated: 2022/10/03 14:43:51 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	key_hook(int keycode, t_data *data)
{
	if (keycode == ESC)
		ft_escape(data);
	else if (keycode == ZOOM_IN || keycode == ZOOM_OUT)
		ft_zoom(data, keycode);
	else if (keycode == UP || keycode == DOWN || \
	keycode == LEFT || keycode == RIGHT)
		ft_move(data, keycode);
	return (0);
}

void	ft_draw(t_map map)
{
	t_data	data;

	data.mlx = mlx_init();
	if (!data.mlx)
	{
		ft_free_coordinate(data.map.coordinate, data.map.height);
		ft_free_int_map(data.map.int_map, data.map.height);
		ft_exit(MLX_INIT_ERROR);
	}
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, TITLE);
	data.img = ft_img_init(data.mlx);
	data.map = map;
	ft_connect_dots(data.img, data.map);
	mlx_put_image_to_window(data.mlx, data.win, data.img.img, 0, 0);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_loop(data.mlx);
}
