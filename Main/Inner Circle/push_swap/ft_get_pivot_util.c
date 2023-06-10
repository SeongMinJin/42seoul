/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pivot_util.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:01:10 by seojin            #+#    #+#             */
/*   Updated: 2022/08/31 13:51:38 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int val)
{
	if (val < 0)
		return (-val);
	return (val);
}

int	ft_get_num(t_stack *a, int pivot)
{
	int	num;

	num = 1;
	while (a)
	{
		if (a->val < pivot)
			num++;
		a = a->next;
	}
	return (num);
}

int	ft_get_smaller_pivot(t_stack *a, int pivot)
{
	int	curr;
	int	sub;

	sub = 2147483647;
	while (a)
	{
		if (a->val < pivot)
		{
			if (ft_abs(pivot - a->val) < sub)
			{
				sub = ft_abs(pivot - a->val);
				curr = a->val;
			}
		}
		a = a->next;
	}
	return (curr);
}

int	ft_get_bigger_pivot(t_stack *a, int pivot)
{
	int	curr;
	int	sub;

	sub = 2147483647;
	while (a)
	{
		if (a->val > pivot)
		{
			if (ft_abs(pivot - a->val) < sub)
			{
				sub = ft_abs(pivot - a->val);
				curr = a->val;
			}
		}
		a = a->next;
	}
	return (curr);
}
