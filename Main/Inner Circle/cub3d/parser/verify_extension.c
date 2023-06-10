/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_extension.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:56:21 by seojin            #+#    #+#             */
/*   Updated: 2022/11/13 14:56:36 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	verify_cub_extension(char *file_name)
{
	char	*dot_position;

	dot_position = ft_strrchr(file_name, '.');
	if (!dot_position)
		ft_error(CUB_EXTENSION_ERR);
	if (ft_strcmp(++dot_position, "cub"))
		ft_error(CUB_EXTENSION_ERR);
}

void	verify_xpm_extension(char *file_name)
{
	char	*dot_position;

	dot_position = ft_strrchr(file_name, '.');
	if (!dot_position)
		ft_error(XPM_EXTENSION_ERR);
	if (ft_strcmp(++dot_position, "xpm"))
		ft_error(XPM_EXTENSION_ERR);
}
