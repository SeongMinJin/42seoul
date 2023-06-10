/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:30:14 by seojin            #+#    #+#             */
/*   Updated: 2022/08/22 13:28:39 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_zoom_in(t_data *data)
{
	if (data->map.scale == 100)
		return ;
	else
		data->map.scale += 5;
	mlx_destroy_image(data->mlx, data->img.img);
	ft_free_coordinate(data->map.coordinate, data->map.height);
	data->img = ft_img_init(data->mlx);
	data->map = ft_create_coordinate(data->map);
	ft_connect_dots(data->img, data->map);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

static void	ft_zoom_out(t_data *data)
{
	if (data->map.scale == 5)
		return ;
	else
		data->map.scale -= 5;
	mlx_destroy_image(data->mlx, data->img.img);
	ft_free_coordinate(data->map.coordinate, data->map.height);
	data->img = ft_img_init(data->mlx);
	data->map = ft_create_coordinate(data->map);
	ft_connect_dots(data->img, data->map);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

void	ft_zoom(t_data *data, int keycode)
{
	if (keycode == ZOOM_IN)
		ft_zoom_in(data);
	else if (keycode == ZOOM_OUT)
		ft_zoom_out(data);
}
