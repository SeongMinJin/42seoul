/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_movement_cnt.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:12:15 by seojin            #+#    #+#             */
/*   Updated: 2022/08/31 13:49:46 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_min_pos(t_stack *a, int min)
{
	int	pos;

	pos = 0;
	while (a->val != min)
	{
		a = a->next;
		pos++;
	}
	return (pos);
}

int	ft_get_valid_pos(t_stack *a, int val)
{
	int	pos;

	pos = 1;
	if (val < ft_get_min(a) || val > ft_get_max(a))
		return (ft_get_min_pos(a, ft_get_min(a)));
	while (a->next)
	{
		if (a->val < val && val < a->next->val)
			return (pos);
		else
			pos++;
		a = a->next;
	}
	return (pos);
}

static int	ft_get_a_movement(t_stack *a, int len, int val)
{
	int	pos;

	if (val > ft_get_max(a) || val < ft_get_min(a))
		pos = ft_get_min_pos(a, ft_get_min(a));
	else if (val < a->val && val > ft_last_node(a)->val)
		return (0);
	else
		pos = ft_get_valid_pos(a, val);
	if (pos <= len / 2)
		return (pos);
	return (len - pos);
}

void	ft_get_movement_cnt(t_stack *a, t_stack *b)
{
	int	i;
	int	a_len;
	int	b_len;

	i = 0;
	a_len = ft_lst_len(a);
	b_len = ft_lst_len(b);
	while (i < b_len / 2)
	{
		b->a_movement = ft_get_a_movement(a, a_len, b->val);
		b->b_movement = i;
		i++;
		b = b->next;
	}
	while (b)
	{
		b->a_movement = ft_get_a_movement(a, a_len, b->val);
		b->b_movement = ft_lst_len(b);
		b = b->next;
	}
}
