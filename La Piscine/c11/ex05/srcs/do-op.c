/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 21:41:06 by seojin            #+#    #+#             */
/*   Updated: 2022/05/04 18:04:50 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

void	ft_operator(int a, int b, int c)
{
	int	(*fp[5])(int, int);

	fp[0] = &ft_add;
	fp[1] = &ft_sub;
	fp[2] = &ft_multiply;
	fp[3] = &ft_div;
	fp[4] = &ft_module;
	ft_putnbr(fp[c](a, b));
}

void	ft_do_op(int a, int b, char c)
{
	if (c == '+')
		ft_operator(a, b, 0);
	else if (c == '-')
		ft_operator(a, b, 1);
	else if (c == '*')
		ft_operator(a, b, 2);
	else if (c == '/')
	{
		if (b == 0)
			ft_putstr("Stop : division by zero");
		else
			ft_operator(a, b, 3);
	}
	else if (c == '%')
	{
		if (b == 0)
			ft_putstr("Stop : division by zero");
		else
			ft_operator(a, b, 4);
	}
}

int	operator_check(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	if (len != 1)
		return (1);
	else if (str[0] == '-' || str[0] == '+')
		return (0);
	else if (str[0] == '*' || str[0] == '/' || str[0] == '%')
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	if (ac != 4)
		return (0);
	else if (operator_check(av[2]))
	{
		ft_putstr("0");
		return (0);
	}
	ft_do_op(ft_atoi(av[1]), ft_atoi(av[3]), av[2][0]);
	return (0);
}
