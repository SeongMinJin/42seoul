/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 21:12:15 by seojin            #+#    #+#             */
/*   Updated: 2022/05/01 16:29:44 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

long	ft_sub(long min, long max)
{
	if (max > min)
		return (max - min);
	else
		return (0);
}

int	*ft_range(int min, int max)
{
	int		*arr;
	int		i;
	long	sub;

	if (min >= max)
		return (0);
	arr = (int *)malloc(sizeof(int) * ft_sub(min, max));
	if (!arr)
		return (0);
	else
	{
		sub = ft_sub(min, max);
		i = 0;
		while (i < sub)
		{
			arr[i] = min;
			i++;
			min++;
		}
	}
	return (arr);
}
