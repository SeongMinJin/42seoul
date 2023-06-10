/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reorder_map_components.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:04:52 by haryu             #+#    #+#             */
/*   Updated: 2022/11/14 17:37:24 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*pass_all_nl(char *file_data, int code)
{
	while (file_data[code] == '\n')
		code++;
	file_data += code;
	return (file_data);
}

static void	ft_mapcompo_free(t_mapcontents *temp)
{
	free(temp->no);
	free(temp->so);
	free(temp->we);
	free(temp->ea);
	free(temp->f);
	free(temp->c);
}

char	*reorder_map_components(t_mapcontents *temp, \
char *file_data, int data_pos)
{
	char	*temp_map;
	char	*temp_map2;

	if (!check_map_flag(temp))
		ft_error(INVALID_MAP);
	file_data = pass_all_nl(file_data, data_pos);
	temp_map = ft_strdup(temp->no);
	temp_map2 = ft_strjoin(temp_map, temp->so);
	free(temp_map);
	temp_map = ft_strjoin(temp_map2, temp->we);
	free(temp_map2);
	temp_map2 = ft_strjoin(temp_map, temp->ea);
	free(temp_map);
	temp_map = ft_strjoin(temp_map2, temp->f);
	free(temp_map2);
	temp_map2 = ft_strjoin(temp_map, temp->c);
	free(temp_map);
	temp_map = ft_strjoin(temp_map2, "\n");
	free(temp_map2);
	temp_map2 = ft_strjoin(temp_map, file_data);
	free(temp_map);
	ft_mapcompo_free(temp);
	return (temp_map2);
}
