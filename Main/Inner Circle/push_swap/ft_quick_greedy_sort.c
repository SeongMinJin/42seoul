/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_greedy_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 13:10:02 by seojin            #+#    #+#             */
/*   Updated: 2022/09/06 20:21:32 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_end_sort(t_stack **a)
{
	int	min;
	int	min_pos;
	int	len;

	min = ft_get_min(*a);
	min_pos = ft_get_min_pos(*a, min);
	len = ft_lst_len(*a);
	if (min_pos >= len / 2)
		while ((*a)->val != min)
			rra(a);
	else
		while ((*a)->val != min)
			ra(a);
}

static void	ft_final_sort(t_stack **a, t_stack **b)
{
	int	movement;
	int	a_pos;
	int	b_pos;

	movement = ft_get_min_movement(*b);
	b_pos = ft_get_min_movement_pos(*b, movement);
	a_pos = ft_get_valid_pos(*a, \
	ft_get_min_movement_val(*b, b_pos));
	ft_optimize(a, b, a_pos, b_pos);
}

static void	ft_init_sort_util(t_stack **a, t_stack **b)
{
	ft_hard_sort(a, b, ft_lst_len(*a));
	pb(b, a);
	rb(b);
}

static void	ft_init_sort(t_stack **a, t_stack **b, \
int pivot_1, int pivot_2)
{
	int	cnt;

	cnt = ft_lst_len(*a);
	while (cnt--)
	{
		if ((*a)->val < pivot_1)
		{
			pb(b, a);
			if (ft_lst_len(*b) > 1)
				rb(b);
		}
		else if (pivot_1 < (*a)->val && (*a)->val < pivot_2)
			pb(b, a);
		else
			ra(a);
	}
	while (ft_lst_len(*a) > 6)
	{
		if ((*a)->val != pivot_1)
			pb(b, a);
		else
			ra(a);
	}
	ft_init_sort_util(a, b);
}

void	ft_quick_greedy_sort(t_stack **a, t_stack **b)
{
	int	pivot_1;
	int	pivot_2;

	pivot_1 = ft_get_pivot(*a, PIVOT_1);
	pivot_2 = ft_get_pivot(*a, PIVOT_2);
	ft_init_sort(a, b, pivot_1, pivot_2);
	while (*b)
	{
		ft_get_movement_cnt(*a, *b);
		ft_final_sort(a, b);
	}
	ft_end_sort(a);
}
