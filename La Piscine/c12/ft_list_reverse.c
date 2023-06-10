/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:09:52 by seojin            #+#    #+#             */
/*   Updated: 2022/07/18 15:30:21 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **head)
{
	t_list	*temp;
	t_list	*tail;

	tail = NULL;
	while (*head)
	{
		temp = (*head)-> next;
		(*head)-> next = tail;
		tail = *head;
		if (!temp)
			return ;
		*head = temp;
	}
}
