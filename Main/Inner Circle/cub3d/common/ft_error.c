/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:54:38 by seojin            #+#    #+#             */
/*   Updated: 2022/11/14 12:38:13 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_error(int flag)
{
	printf("Error\n");
	if (flag == MALLOC_ERR)
		printf("Malloc error.\n");
	else if (flag == AC_ERR)
		printf("Argument must be `ONE' .cub extension file.\n");
	else if (flag == CUB_EXTENSION_ERR)
		printf("File extension must be `.cub'.\n");
	else if (flag == XPM_EXTENSION_ERR)
		printf("Texture file extension must be `.xpm'.\n");
	else if (flag == NO_SUCH_FILE)
		printf("No such file.\n");
	else if (flag == INVALID_IDENTIFIER)
		printf("Invalid identifier.\n");
	else if (flag == INVALID_RGB)
		printf("Invalid RGB value.\n");
	else if (flag == INVALID_MAP)
		printf("Invalid map data.\n");
	else if (flag == MULTIPLE_SPAWN)
		printf("Map must be consist of `ONE' spawn area.\n");
	else if (flag == NO_SPAWN_AREA)
		printf("No spawn area.\n");
	else if (flag == XPM_FILE_ERR)
		printf("Invalid xpm file.\n");
	exit(flag);
}
