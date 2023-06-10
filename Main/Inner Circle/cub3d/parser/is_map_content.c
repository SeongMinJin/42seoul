/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_content.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:56:03 by seojin            #+#    #+#             */
/*   Updated: 2022/11/13 14:56:41 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	is_map_content(char c)
{
	return ((c == EMPTY_SPACE || c == WALL || c == SPAWN_N || \
	c == SPAWN_S || c == SPAWN_W || c == SPAWN_E || c == NONE));
}
