/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hard_sort_util.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 11:51:38 by seojin            #+#    #+#             */
/*   Updated: 2022/08/30 12:22:21 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_get_rotate_cnt(t_stack **a, int min, int max)
{
	int	i;
	int	rotate;

	i = 0;
	rotate = 0;
	while ((*a)->val != min && (*a)->val != max)
	{
		ft_simul_rotate(a);
		rotate++;
	}
	while (i++ < rotate)
		ft_simul_reverse_rotate(a);
	return (rotate);
}

static int	ft_get_reverse_rotate_cnt(t_stack **a, int min, int max)
{
	int	i;
	int	reverse;

	i = 0;
	reverse = 0;
	while ((*a)->val != min && (*a)->val != max)
	{
		ft_simul_reverse_rotate(a);
		reverse++;
	}
	while (i++ < reverse)
		ft_simul_rotate(a);
	return (reverse);
}

static void	ft_simulation(t_stack **a, int min, int max)
{
	int	i;
	int	rotate;
	int	reverse;

	i = 0;
	rotate = ft_get_rotate_cnt(a, min, max);
	reverse = ft_get_reverse_rotate_cnt(a, min, max);
	if (rotate < reverse)
		while ((*a)->val != min && (*a)->val != max)
			ra(a);
	else
		while ((*a)->val != min && (*a)->val != max)
			rra(a);
}

void	ft_optimization(t_stack **a, t_stack **b, int min, int max)
{
	ft_simulation(a, min, max);
	pb(b, a);
}
