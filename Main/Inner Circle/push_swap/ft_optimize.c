/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 12:01:10 by seojin            #+#    #+#             */
/*   Updated: 2022/08/31 13:52:10 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_case1(t_stack **a, t_stack **b, int a_pos, int b_pos)
{
	int	a_len;
	int	b_len;

	a_len = ft_lst_len(*a);
	b_len = ft_lst_len(*b);
	while (a_pos && b_pos)
	{
		a_pos--;
		b_pos--;
		rr(a, b);
	}
	if (a_pos)
	{
		while (a_pos--)
			ra(a);
		pa(a, b);
	}
	else
	{
		while (b_pos--)
			rb(b);
		pa(a, b);
	}
}

static void	ft_case2(t_stack **a, t_stack **b, int a_pos, int b_pos)
{
	int	a_len;
	int	b_len;

	a_len = ft_lst_len(*a);
	b_len = ft_lst_len(*b);
	a_pos = a_len - a_pos;
	b_pos = b_len - b_pos;
	while (a_pos && b_pos)
	{
		a_pos--;
		b_pos--;
		rrr(a, b);
	}
	if (a_pos)
	{
		while (a_pos--)
			rra(a);
		pa(a, b);
	}
	else
	{
		while (b_pos--)
			rrb(b);
		pa(a, b);
	}
}

static void	ft_case3(t_stack **a, t_stack **b, int a_pos, int b_pos)
{
	int	a_len;
	int	b_len;

	a_len = ft_lst_len(*a);
	b_len = ft_lst_len(*b);
	a_pos = a_len - a_pos;
	while (a_pos--)
		rra(a);
	while (b_pos--)
		rb(b);
	pa(a, b);
}

static void	ft_case4(t_stack **a, t_stack **b, int a_pos, int b_pos)
{
	int	a_len;
	int	b_len;

	a_len = ft_lst_len(*a);
	b_len = ft_lst_len(*b);
	b_pos = b_len - b_pos;
	while (a_pos--)
		ra(a);
	while (b_pos--)
		rrb(b);
	pa(a, b);
}

void	ft_optimize(t_stack **a, t_stack **b, int a_pos, int b_pos)
{
	int	a_len;
	int	b_len;

	a_len = ft_lst_len(*a);
	b_len = ft_lst_len(*b);
	if (a_pos <= a_len / 2 && b_pos <= b_len / 2)
		ft_case1(a, b, a_pos, b_pos);
	else if (a_pos >= a_len / 2 && b_pos >= b_len / 2)
		ft_case2(a, b, a_pos, b_pos);
	else if (a_pos >= a_len / 2 && b_pos <= b_len / 2)
		ft_case3(a, b, a_pos, b_pos);
	else
		ft_case4(a, b, a_pos, b_pos);
}
