/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 10:58:35 by seojin            #+#    #+#             */
/*   Updated: 2022/07/18 16:05:21 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*new;
	t_list	*head;
	t_list	*temp;

	new = ft_create_elem(data);
	if (!*begin_list)
	{
		*begin_list = new;
		return ;	
	}
	if (!new)
		return ;
	if (cmp(data, (*begin_list)->data) <= 0)
	{
		new -> next = *begin_list;
		*begin_list = new;
		return ;
	}
	head = *begin_list;
	while (head -> next && cmp(new -> data, (head -> next)->data) >= 0)
		head = head -> next;
	if (!(head->next))
		head -> next = new;
	else
	{
		temp = head -> next;
		head -> next = new;
		new -> next = temp;
	}
}
