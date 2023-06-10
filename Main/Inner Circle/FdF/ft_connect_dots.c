/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_connect_dots.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:36:49 by seojin            #+#    #+#             */
/*   Updated: 2022/10/19 12:05:05 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_draw_line2(t_img img, t_coordinate *c1, \
t_coordinate *c2, t_map map)
{
	int		i;
	double	len;

	len = sqrt(pow(fabs(c1->y - c2->y), 2) + pow(fabs(c1->x - c2->x), 2));
	i = 0;
	while (i < map.scale * len)
	{
		if ((0 <= c1->x + i / len && c1->x + i / len < WIDTH) && \
		(-len * 1.2 <= c1->y + ((c2->y - c1->y) / (c2->x - c1->x)) \
		* i / len && c1->y + ((c2->y - c1->y) / (c2->x - c1->x)) * i \
		/ len < HEIGHT + len * 1.2))
			ft_mlx_pixel_put(&img, c1->x + i / len, c1->y + ((c2->y - c1->y) / \
			(c2->x - c1->x)) * i / len, 0xFFFFFF);
		else
			break ;
		i++;
	}
}

static void	ft_draw_line3(t_img img, t_coordinate *head, \
t_coordinate *next_head, t_map map)
{
	while (head)
	{
		ft_draw_line2(img, next_head, head, map);
		head = head->next;
		next_head = next_head->next;
	}
}

static void	ft_draw_line(t_img img, t_coordinate *head, t_map map)
{
	while (head->next)
	{
		ft_draw_line2(img, head, head->next, map);
		head = head->next;
	}
}

void	ft_connect_dots(t_img img, t_map map)
{
	int	i;

	i = 0;
	while (i < map.height)
		ft_draw_line(img, *(map.coordinate + i++), map);
	i = 0;
	while (i < map.height - 1)
	{
		ft_draw_line3(img, *(map.coordinate + i), \
		*(map.coordinate + i + 1), map);
		i++;
	}
}
