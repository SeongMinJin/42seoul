/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 09:09:56 by seojin            #+#    #+#             */
/*   Updated: 2022/07/18 16:03:25 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_sort(t_list **list, int (*cmp)())
{
	t_list	*head;
	void	*temp;

	if (!*list)
		return ;
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
