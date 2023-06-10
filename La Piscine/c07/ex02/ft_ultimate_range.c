/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 21:38:57 by seojin            #+#    #+#             */
/*   Updated: 2022/05/01 03:45:36 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

long	ft_sub(long min, long max)
{
	if (min >= max)
		return (1);
	else
		return (max - min);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*arr;
	int	i;
	int	size;

	arr = (int *)malloc(sizeof(int) * ft_sub(min, max));
	if (!arr)
		return (-1);
	else if (ft_sub(min, max) > 2147483647)
		return (-1);
	else if (min >= max)
	{
		*arr = 0;
		return (0);
	}
	i = 0;
	size = ft_sub(min, max);
	while (i < size)
	{
		arr[i] = min;
		i++;
		min++;
	}
	range[0] = arr;
	return (size);
}
