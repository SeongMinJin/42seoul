/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checeer_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:32:13 by seojin            #+#    #+#             */
/*   Updated: 2022/08/31 15:30:18 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	csa(t_stack **a)
{
	t_stack	*tmp;

	if (ft_lst_len(*a) > 1)
	{
		tmp = (*a)->next;
		(*a)->next = tmp->next;
		tmp->next = *a;
		*a = tmp;
	}
}

void	csb(t_stack **b)
{
	t_stack	*tmp;

	if (ft_lst_len(*b) > 1)
	{
		tmp = (*b)->next;
		(*b)->next = tmp->next;
		tmp->next = *b;
		*b = tmp;
	}
}

void	css(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (ft_lst_len(*a) > 1)
	{
		tmp = (*a)->next;
		(*a)->next = tmp->next;
		tmp->next = *a;
		*a = tmp;
	}
	if (ft_lst_len(*b) > 1)
	{
		tmp = (*b)->next;
		(*b)->next = tmp->next;
		tmp->next = *b;
		*b = tmp;
	}
}
