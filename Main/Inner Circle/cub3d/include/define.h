/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:55:45 by seojin            #+#    #+#             */
/*   Updated: 2022/11/14 12:38:18 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

/*-----error code-----*/
# define MALLOC_ERR -1
# define AC_ERR 1
# define CUB_EXTENSION_ERR 2
# define XPM_EXTENSION_ERR 3
# define NO_SUCH_FILE 4
# define MISS_ORDER_IDENTIFIER 5
# define INVALID_IDENTIFIER 6
# define INVALID_RGB 7
# define INVALID_MAP 8
# define MULTIPLE_SPAWN 9
# define NO_SPAWN_AREA 10
# define XPM_FILE_ERR 11

/*-------window-------*/
# define WIDTH 1080
# define HEIGHT 720

/*-----map content----*/
# define EMPTY_SPACE '0'
# define WALL '1'
# define SPAWN_N 'N'
# define SPAWN_S 'S'
# define SPAWN_W 'W'
# define SPAWN_E 'E'
# define NONE ' '

/*------key code-----*/
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define LEFT 123
# define RIGHT 124

/*--------RGB--------*/
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define YELLOW 0x00FFFF00
# define WHITE 0x00FFFFFF

/*-----ORIENTATION-----*/
# define NORTH 1
# define SOUTH 2
# define WEST 3
# define EAST 4
# define SIDE 5
# define FACE 6
#endif