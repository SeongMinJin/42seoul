/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_coordinate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:04:10 by seojin            #+#    #+#             */
/*   Updated: 2022/08/22 15:02:02 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_append_back(t_coordinate **head, t_coordinate *new_node)
{
	t_coordinate	*temp;

	if (!*head)
		*head = new_node;
	else
	{
		temp = *head;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}
}

static t_coordinate	*ft_create_node(double x, double y)
{
	t_coordinate	*node;

	node = (t_coordinate *)malloc(sizeof(t_coordinate));
	if (!node)
		return (0);
	node->x = x;
	node->y = y;
	node->next = 0;
	return (node);
}

static t_coordinate	*ft_get_coordinate(int *int_map, \
t_map map, int benchmark_x, int benchmark_y)
{
	int				i;
	t_coordinate	*head;
	t_coordinate	*new_node;

	i = 0;
	head = NULL;
	while (i < map.width)
	{
		new_node = ft_create_node(benchmark_x + (i * map.scale), \
		benchmark_y + ((tan(ft_deg_to_rad(map.degree)) * i - \
		*(int_map + i) * tan(ft_deg_to_rad(30))) * map.scale));
		if (!new_node)
		{
			ft_free_lst(head);
			return (0);
		}
		ft_append_back(&head, new_node);
		i++;
	}
	return (head);
}

t_map	ft_create_coordinate(t_map map)
{
	int	i;

	map.coordinate = (t_coordinate **)malloc(map.height * \
	sizeof(t_coordinate *));
	if (!map.coordinate)
	{
		ft_free_int_map(map.int_map, map.height);
		ft_exit(MALLOC_ERROR);
	}
	i = 0;
	while (i < map.height)
	{
		*(map.coordinate + i) = ft_get_coordinate(*(map.int_map + i), map, \
		map.benchmark_x - (i * map.scale), \
		map.benchmark_y + (i * map.scale * tan(ft_deg_to_rad(30))));
		if (!*((map.coordinate) + i))
		{
			ft_free_int_map(map.int_map, map.height);
			ft_free_coordinate(map.coordinate, i);
			ft_exit(MALLOC_ERROR);
		}
		i++;
	}
	return (map);
}
