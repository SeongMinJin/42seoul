/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_greedy_sort_util.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:53:50 by seojin            #+#    #+#             */
/*   Updated: 2022/08/31 11:53:13 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_min_movement_pos(t_stack *stack, int movement)
{
	int	pos;

	pos = 0;
	while (stack->a_movement + stack->b_movement != movement)
	{
		stack = stack->next;
		pos++;
	}
	return (pos);
}

int	ft_get_min_movement_val(t_stack *stack, int pos)
{
	while (pos--)
		stack = stack->next;
	return (stack->val);
}

int	ft_get_min_movement(t_stack *stack)
{
	int	movement;

	movement = 2147483647;
	while (stack)
	{
		if (stack->a_movement + stack->b_movement < movement)
			movement = stack->a_movement + stack->b_movement;
		stack = stack->next;
	}
	return (movement);
}
