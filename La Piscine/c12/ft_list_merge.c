/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 09:06:39 by seojin            #+#    #+#             */
/*   Updated: 2022/07/18 15:56:27 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*head;
	if (!*begin_list1)
		return ;
	head = *begin_list1;
	while (head -> next)
		head = head -> next;
	head -> next = begin_list2;
}
