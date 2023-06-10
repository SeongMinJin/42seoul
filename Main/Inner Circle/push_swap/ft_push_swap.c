/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 13:33:26 by seojin            #+#    #+#             */
/*   Updated: 2022/08/30 19:00:41 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_hard_sort(t_stack **a, t_stack **b, int len)
{
	if (ft_ascending_check(*a))
		return ;
	else if (len == 2)
		ft_sort_2(a);
	else if (len == 3)
		ft_sort_3(a);
	else if (len == 4)
		ft_sort_4(a, b);
	else if (len == 5)
		ft_sort_5(a, b);
	else
		ft_sort_6(a, b);
}

void	ft_push_swap(t_stack **a, t_stack **b, int len)
{
	if (ft_ascending_check(*a))
		return ;
	else if (len < 7)
		ft_hard_sort(a, b, len);
	else
		ft_quick_greedy_sort(a, b);
}
