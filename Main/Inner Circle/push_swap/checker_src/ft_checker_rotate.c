/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:47:24 by seojin            #+#    #+#             */
/*   Updated: 2022/08/31 15:31:10 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	cra(t_stack **a)
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

void	crb(t_stack **b)
{
	t_stack	*tmp;

	if (ft_lst_len(*b) > 1)
	{
		tmp = ft_last_node(*b);
		tmp->next = *b;
		*b = (*b)->next;
		(tmp->next)->next = 0;
	}
}

void	crr(t_stack **a, t_stack **b)
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
}
