/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 06:42:55 by seojin            #+#    #+#             */
/*   Updated: 2022/08/30 11:54:53 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_check_dup(t_stack *a, int val)
{
	while (a)
	{
		if (a->val == val)
			return (DUP);
		a = a->next;
	}
	return (0);
}

static long	ft_advanced_atoi(char *str)
{
	long	num;
	long	sign;

	num = 0;
	sign = 1;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	if ('0' > *str || *str > '9')
		return (NAN);
	while ('0' <= *str && *str <= '9')
	{
		num = num * 10 + *str++ - 48;
		if (num > 2147483648)
			return (NAI);
	}
	if (*str != ' ' && *str != '\0')
		return (NAN);
	if (num * sign < -2147483648 || num * sign > 2147483647)
		return (NAI);
	return (num * sign);
}

static void	ft_init_2(t_stack **a, char *str)
{
	long	val;

	while (*str)
	{
		while (*str && *str == ' ')
			str++;
		if (!*str)
			break ;
		val = ft_advanced_atoi(str);
		if (val == NAN || val == NAI)
		{
			ft_free_lst(a);
			ft_exit(ERROR);
		}
		if (ft_check_dup(*a, (int)val) == DUP)
		{
			ft_free_lst(a);
			ft_exit(ERROR);
		}
		ft_append_back(a, ft_new_node((int)val));
		while (*str && *str != ' ')
			str++;
	}
}

t_stack	*ft_init(char **av)
{
	t_stack	*a;

	a = 0;
	while (*av)
	{
		ft_init_2(&a, *av);
		av++;
	}
	return (a);
}
