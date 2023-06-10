/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 13:23:06 by seojin            #+#    #+#             */
/*   Updated: 2022/09/06 21:44:23 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac == 1)
		ft_exit(NOT_ENOUGH);
	a = ft_init(++av);
	b = 0;
	ft_push_swap(&a, &b, ft_lst_len(a));
	ft_free_lst(&a);
	return (0);
}
