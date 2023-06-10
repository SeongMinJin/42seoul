/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:09:32 by seojin            #+#    #+#             */
/*   Updated: 2022/08/31 20:15:12 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_swap(t_stack **a, t_stack **b, char *buf)
{
	if (!cmp(buf, "sa"))
		csa(a);
	else if (!cmp(buf, "sb"))
		csb(b);
	else
		css(a, b);
}

static void	ft_push(t_stack **a, t_stack **b, char *buf)
{
	if (!cmp(buf, "pa"))
		cpa(a, b);
	else
		cpb(b, a);
}

static void	ft_rotate(t_stack **a, t_stack **b, char *buf)
{
	if (!cmp(buf, "ra"))
		cra(a);
	else if (!cmp(buf, "rb"))
		crb(b);
	else
		crr(a, b);
}

static void	ft_reverse(t_stack **a, t_stack **b, char *buf)
{
	if (!cmp(buf, "rra"))
		crra(a);
	else if (!cmp(buf, "rrb"))
		crrb(b);
	else
		crrr(a, b);
}

void	ft_verify2(t_stack **a, t_stack **b, char *s)
{
	if (*s == 0)
		return ;
	else if (!cmp(s, "sa") || !cmp(s, "sb") || !cmp(s, "ss"))
		ft_swap(a, b, s);
	else if (!cmp(s, "pa") || !cmp(s, "pb"))
		ft_push(a, b, s);
	else if (!cmp(s, "ra") || !cmp(s, "rb") || !cmp(s, "rr"))
		ft_rotate(a, b, s);
	else if (!cmp(s, "rra") || !cmp(s, "rrb") || !cmp(s, "rrr"))
		ft_reverse(a, b, s);
	else
		ft_error(a, b);
}
