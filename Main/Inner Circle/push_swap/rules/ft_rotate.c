/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:47:24 by seojin            #+#    #+#             */
/*   Updated: 2022/08/30 12:03:52 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_simul_rotate(t_stack **a)
{
	t_stack	*tmp;

	if (ft_lst_len(*a) > 1)
	{
		tmp = ft_last_node(*a);
		tmp->next = *a;
		*a = (*a)->next;
		(tmp->next)->next = 0;
	}
}

void	ra(t_stack **a)
{
	t_stack	*tmp;

	if (ft_lst_len(*a) > 1)
	{
		tmp = ft_last_node(*a);
		tmp->next = *a;
		*a = (*a)->next;
		(tmp->next)->next = 0;
		write(1, "ra\n", 3);
	}
}

void	rb(t_stack **b)
{
	t_stack	*tmp;

	if (ft_lst_len(*b) > 1)
	{
		tmp = ft_last_node(*b);
		tmp->next = *b;
		*b = (*b)->next;
		(tmp->next)->next = 0;
		write(1, "rb\n", 3);
	}
}

void	rr(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (ft_lst_len(*a) > 1)
	{
		tmp = ft_last_node(*a);
		tmp->next = *a;
		*a = (*a)->next;
		(tmp->next)->next = 0;
	}
	if (ft_lst_len(*b) > 1)
	{
		tmp = ft_last_node(*b);
		tmp->next = *b;
		*b = (*b)->next;
		(tmp->next)->next = 0;
	}
	write(1, "rr\n", 3);
}
