/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_user.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:55:38 by seojin            #+#    #+#             */
/*   Updated: 2022/11/13 14:56:44 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	get_user_orientation(t_user *user, int orientation);

t_user	*new_user(t_map *map)
{
	t_user	*user;

	user = (t_user *)malloc(sizeof(t_user));
	if (!user)
		ft_error(MALLOC_ERR);
	get_user_orientation(user, map->spawn_orientation);
	user->curr_x = map->spawn_x + 0.5;
	user->curr_y = map->spawn_y + 0.5;
	return (user);
}

static void	get_user_orientation(t_user *user, int orientation)
{
	user->dir_x = 0;
	user->dir_y = 0;
	user->plane_x = 0;
	user->plane_y = 0;
	if (orientation == SPAWN_N)
	{
		user->dir_y = -1;
		user->plane_x = 0.66;
	}
	else if (orientation == SPAWN_S)
	{
		user->dir_y = 1;
		user->plane_x = -0.66;
	}
	else if (orientation == SPAWN_W)
	{
		user->dir_x = -1;
		user->plane_y = -0.66;
	}
	else
	{
		user->dir_x = 1;
		user->plane_y = 0.66;
	}
}
