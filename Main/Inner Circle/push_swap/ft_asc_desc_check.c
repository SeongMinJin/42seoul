/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asc_desc_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 13:46:52 by seojin            #+#    #+#             */
/*   Updated: 2022/08/30 12:17:56 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ascending_check(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->val < (stack->next)->val)
			stack = stack->next;
		else
			return (0);
	}
	return (1);
}

int	ft_descending_check(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->val > (stack->next)->val)
			stack = stack->next;
		else
			return (0);
	}
	return (1);
}
