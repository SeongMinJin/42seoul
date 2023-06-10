/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hard_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 18:54:54 by seojin            #+#    #+#             */
/*   Updated: 2022/08/30 12:21:55 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_6(t_stack **a, t_stack **b)
{
	ft_optimization(a, b, ft_get_min(*a), ft_get_max(*a));
	ft_sort_5(a, b);
	if ((*b)->val < (*a)->val)
		pa(a, b);
	else if ((*b)->val > ft_last_node(*a)->val)
	{
		pa(a, b);
		ra(a);
	}
}

void	ft_sort_5(t_stack **a, t_stack **b)
{
	ft_optimization(a, b, ft_get_min(*a), ft_get_max(*a));
	ft_sort_4(a, b);
	if ((*b)->val < (*a)->val)
		pa(a, b);
	else if ((*b)->val > ft_last_node(*a)->val)
	{
		pa(a, b);
		ra(a);
	}
}

void	ft_sort_4(t_stack **a, t_stack **b)
{
	ft_optimization(a, b, ft_get_min(*a), ft_get_max(*a));
	ft_sort_3(a);
	if ((*b)->val < (*a)->val)
		pa(a, b);
	else if ((*b)->val > ft_last_node(*a)->val)
	{
		pa(a, b);
		ra(a);
	}
}

void	ft_sort_3(t_stack **a)
{
	if (ft_ascending_check(*a))
		return ;
	else if ((*a)->val == ft_get_min(*a))
	{
		sa(a);
		ra(a);
	}
	else if ((*a)->val != ft_get_min(*a) && (*a)->val != ft_get_max(*a) \
	&& ft_last_node(*a)->val == ft_get_max(*a))
		sa(a);
	else if ((*a)->val != ft_get_min(*a) && (*a)->val != ft_get_max(*a) \
	&& ft_last_node(*a)->val == ft_get_min(*a))
		rra(a);
	else if ((*a)->val == ft_get_max(*a) && \
	ft_last_node(*a)->val != ft_get_min(*a))
		ra(a);
	else if (ft_descending_check(*a))
	{
		sa(a);
		rra(a);
	}
}

void	ft_sort_2(t_stack **a)
{
	if ((*a)->val > ((*a)->next)->val)
		sa(a);
}
