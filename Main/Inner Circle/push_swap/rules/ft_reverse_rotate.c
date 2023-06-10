/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:01:34 by seojin            #+#    #+#             */
/*   Updated: 2022/08/31 13:55:30 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_simul_reverse_rotate(t_stack **a)
{
	t_stack	*last;
	t_stack	*before_last;

	if (ft_lst_len(*a) > 1)
	{
		last = ft_last_node(*a);
		before_last = ft_before_last_node(*a);
		before_last->next = 0;
		last->next = *a;
		*a = last;
	}
}

void	rra(t_stack **a)
{
	t_stack	*last;
	t_stack	*before_last;

	if (ft_lst_len(*a) > 1)
	{
		last = ft_last_node(*a);
		before_last = ft_before_last_node(*a);
		before_last->next = 0;
		last->next = *a;
		*a = last;
		write(1, "rra\n", 4);
	}
}

void	rrb(t_stack **b)
{
	t_stack	*last;
	t_stack	*before_last;

	if (ft_lst_len(*b) > 1)
	{
		last = ft_last_node(*b);
		before_last = ft_before_last_node(*b);
		before_last->next = 0;
		last->next = *b;
		*b = last;
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_stack **a, t_stack **b)
{
	t_stack	*last;
	t_stack	*before_last;

	if (ft_lst_len(*a) > 1)
	{
		last = ft_last_node(*a);
		before_last = ft_before_last_node(*a);
		before_last->next = 0;
		last->next = *a;
		*a = last;
	}
	if (ft_lst_len(*b) > 1)
	{
		last = ft_last_node(*b);
		before_last = ft_before_last_node(*b);
		before_last->next = 0;
		last->next = *b;
		*b = last;
	}
	write(1, "rrr\n", 4);
}
