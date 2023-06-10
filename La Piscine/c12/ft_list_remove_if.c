/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 08:21:08 by seojin            #+#    #+#             */
/*   Updated: 2022/07/18 18:25:36 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void \
		*data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*curr;
	t_list	*dust;

	if (!begin_list || !*begin_list)
		return ;
	while (!cmp((*begin_list)-> data, data_ref))
	{
		curr = *begin_list;

		*begin_list = (*begin_list)-> next;
	}
	curr = *begin_list;
	while (curr -> next)
	{
		if (!cmp((curr -> next)-> data, data_ref))
		{
			dust = curr -> next;

			curr -> next = dust -> next;
		}
		else
			curr = curr -> next;
	}
}
