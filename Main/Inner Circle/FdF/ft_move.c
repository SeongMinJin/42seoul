/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:09:27 by seojin            #+#    #+#             */
/*   Updated: 2022/08/22 13:28:23 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_up(t_data *data, int unit)
{
	data->map.benchmark_y -= unit;
	mlx_destroy_image(data->mlx, data->img.img);
	ft_free_coordinate(data->map.coordinate, data->map.height);
	data->img = ft_img_init(data->mlx);
	data->map = ft_create_coordinate(data->map);
	ft_connect_dots(data->img, data->map);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

static void	ft_down(t_data *data, int unit)
{
	data->map.benchmark_y += unit;
	mlx_destroy_image(data->mlx, data->img.img);
	ft_free_coordinate(data->map.coordinate, data->map.height);
	data->img = ft_img_init(data->mlx);
	data->map = ft_create_coordinate(data->map);
	ft_connect_dots(data->img, data->map);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

static void	ft_left(t_data *data, int unit)
{
	data->map.benchmark_x -= unit;
	mlx_destroy_image(data->mlx, data->img.img);
	ft_free_coordinate(data->map.coordinate, data->map.height);
	data->img = ft_img_init(data->mlx);
	data->map = ft_create_coordinate(data->map);
	ft_connect_dots(data->img, data->map);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

static void	ft_right(t_data *data, int unit)
{
	data->map.benchmark_x += unit;
	mlx_destroy_image(data->mlx, data->img.img);
	ft_free_coordinate(data->map.coordinate, data->map.height);
	data->img = ft_img_init(data->mlx);
	data->map = ft_create_coordinate(data->map);
	ft_connect_dots(data->img, data->map);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

void	ft_move(t_data *data, int keycode)
{
	int	unit;

	unit = 50;
	if (keycode == UP)
		ft_up(data, unit);
	else if (keycode == DOWN)
		ft_down(data, unit);
	else if (keycode == LEFT)
		ft_left(data, unit);
	else if (keycode == RIGHT)
		ft_right(data, unit);
}
