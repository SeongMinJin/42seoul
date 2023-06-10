/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 17:34:26 by seojin            #+#    #+#             */
/*   Updated: 2022/08/22 14:45:18 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_lst(t_coordinate *head)
{
	t_coordinate	*temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

void	ft_free_coordinate(t_coordinate **coordinate, int idx)
{
	int	i;

	i = 0;
	while (i < idx)
	{
		ft_free_lst(*(coordinate + i));
		i++;
	}
	free(coordinate);
}

void	ft_free_int_map(int **arr, int idx)
{
	int	i;

	i = 0;
	while (i < idx)
	{
		free(*(arr + i));
		i++;
	}
	free(arr);
}

void	ft_free_str_map(char **str)
{
	char	**temp;

	temp = str;
	while (*temp)
	{
		free(*temp);
		temp++;
	}
	free(str);
}
