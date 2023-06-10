/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_file_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:56:22 by seojin            #+#    #+#             */
/*   Updated: 2022/11/14 16:13:15 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*verify_file_format(char *file_data)
{
	char	*temp;
	char	*ret;

	if (order_is_okay(file_data))
		temp = file_data;
	else
	{
		temp = reorder_map_data(file_data);
		free(file_data);
	}
	ret = temp;
	temp = verify_wall_texture_data_format(temp);
	temp = verify_ceilling_floor_data_format(temp);
	verify_map_data_format(temp);
	return (ret);
}
