/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_is_okay.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 00:59:22 by haryu             #+#    #+#             */
/*   Updated: 2022/11/13 15:58:07 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	is_okay(char *file_data, int *i, char *type)
{
	int	j;

	j = *i;
	while (file_data[j] && file_data[j] != '\n')
	{
		if (file_data[j] == type[0] && file_data[j + 1] == type[1])
		{
			while (file_data[j] != '\n')
				j++;
			while (file_data[j] < 65 || file_data[j] > 90)
				j++;
			*i = j;
			return (1);
		}
		j++;
	}
	return (0);
}

int	is_okay_fc(char *file_data, int *i)
{
	int	j;

	j = *i;
	while (file_data[j])
	{
		if (file_data[j] == 'F')
		{
			while (file_data[j])
			{
				if (file_data[j] == 'C')
					return (1);
				j++;
			}
		}
		j++;
	}
	return (0);
}

int	order_is_okay(char *file_data)
{
	int	i;

	i = -1;
	while (file_data[++i])
	{
		if (file_data[i] == 'N' && file_data[i + 1] == 'O' && \
is_okay(file_data, &i, "NO"))
		{
			if (is_okay(file_data, &i, "SO"))
			{
				if (is_okay(file_data, &i, "WE"))
				{
					if (is_okay(file_data, &i, "EA"))
					{
						return (is_okay_fc(file_data, &i));
					}
					return (0);
				}
				return (0);
			}
			return (0);
		}
		return (0);
	}
	return (0);
}
