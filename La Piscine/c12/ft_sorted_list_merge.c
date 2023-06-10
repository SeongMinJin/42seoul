/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 11:27:40 by seojin            #+#    #+#             */
/*   Updated: 2022/07/18 16:07:18 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

static t_list	*ft_get_last_node(t_list *list)
{
	while (list -> next)
		list = list -> next;
	return (list);
}

static void	my_list_sort(t_list **list, int (*cmp)())
{
	t_list	*head;
	void	*temp;

	head = *list;
	while (head -> next)
	{
		if (cmp(head -> data, (head -> next)-> data) > 0)
		{
			temp = head -> data;
			head -> data = (head -> next)-> data;
			(head -> next)-> data = temp;
			head = *list;
		}
		else
			head = head -> next;
	}
}

void	ft_sorted_list_merge(t_list **begin_list1, \
		t_list *begin_list2, int (*cmp)())
{
	t_list	*l1_last;
	t_list	*l2_last;

	if (!*begin_list1)
	{
		*(begin_list1) = begin_list2;
		return ;
	}
	l1_last = ft_get_last_node(*begin_list1);
	l2_last = ft_get_last_node(begin_list2);
	if (cmp(l1_last -> data, begin_list2 -> data) <= 0)
		l1_last -> next = begin_list2;
	else if (cmp(l2_last -> data, (*begin_list1)-> data) <= 0)
	{
		l2_last -> next = *begin_list1;
		*begin_list1 = begin_list2;
	}
	else
	{
		l1_last -> next = begin_list2;
		my_list_sort(begin_list1, cmp);
	}
}
