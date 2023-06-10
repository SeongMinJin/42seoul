/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pivot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 17:42:44 by seojin            #+#    #+#             */
/*   Updated: 2022/08/31 14:10:58 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_pivot_1(t_stack *a, int min, long max, long len)
{
	int	num;
	int	tmp_pivot;

	tmp_pivot = (min + max) / 3;
	num = ft_get_num(a, tmp_pivot);
	if (num > len / 3 || num < len / 3)
	{
		if (num > len / 3)
		{
			while (num > len / 3)
			{
				tmp_pivot = ft_get_smaller_pivot(a, tmp_pivot);
				num = ft_get_num(a, tmp_pivot);
			}
		}
		else
		{
			while (num < len / 3)
			{
				tmp_pivot = ft_get_bigger_pivot(a, tmp_pivot);
				num = ft_get_num(a, tmp_pivot);
			}
		}
	}
	return (tmp_pivot);
}

int	ft_get_pivot_2(t_stack *a, int min, long max, long len)
{
	int	num;
	int	tmp_pivot;

	tmp_pivot = (min + max) / 3 * 2;
	num = ft_get_num(a, tmp_pivot);
	if (num > len / 3 * 2 || num < len / 3 * 2)
	{
		if (num > len / 3 * 2)
		{
			while (num > len / 3 * 2)
			{
				tmp_pivot = ft_get_smaller_pivot(a, tmp_pivot);
				num = ft_get_num(a, tmp_pivot);
			}
		}
		else
		{
			while (num < len / 3 * 2)
			{
				tmp_pivot = ft_get_bigger_pivot(a, tmp_pivot);
				num = ft_get_num(a, tmp_pivot);
			}
		}
	}
	return ((int)tmp_pivot);
}

int	ft_get_pivot(t_stack *a, int standard)
{
	if (standard == PIVOT_1)
		return (ft_get_pivot_1(a, ft_get_min(a), \
		ft_get_max(a), ft_lst_len(a)));
	else
		return (ft_get_pivot_2(a, ft_get_min(a), \
		ft_get_max(a), ft_lst_len(a)));
}
