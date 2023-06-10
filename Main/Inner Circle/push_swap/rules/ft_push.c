/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:40:59 by seojin            #+#    #+#             */
/*   Updated: 2022/08/30 12:08:41 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*head;

	if (*b)
	{
		head = *b;
		*b = (*b)->next;
		head->next = *a;
		*a = head;
		write(1, "pa\n", 3);
	}
}

void	pb(t_stack **b, t_stack **a)
{
	t_stack	*head;

	if (*a)
	{
		head = *a;
		*a = (*a)->next;
		head->next = *b;
		*b = head;
		write(1, "pb\n", 3);
	}
}
