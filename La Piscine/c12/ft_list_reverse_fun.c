/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 10:44:00 by seojin            #+#    #+#             */
/*   Updated: 2022/07/18 10:52:46 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

static int	my_list_size(t_list *list)
{
	int	size;

	size = 0;
	while (list)
	{
		list = list -> next;
		size++;
	}
	return (size);
}

t_list	*ft_get_nth_list(t_list *list, int n)
{
	while (n > 0)
	{
		list = list -> next;
		n--;
	}
	return (list);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		size;
	int		i;
	void	*temp;
	t_list	*front;
	t_list	*back;	

	size = my_list_size(begin_list);
	i = 0;
	while (i < size / 2)
	{
		front = ft_get_nth_list(begin_list, i);
		back = ft_get_nth_list(begin_list, size - 1 - i);
		temp = front -> data;
		front -> data = back -> data;
		back -> data = temp;
		i++;
	}
}
