/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:18:09 by seojin            #+#    #+#             */
/*   Updated: 2022/07/18 15:28:55 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

static void	my_list_push_back(t_list **begin_list, t_list *new)
{
	t_list	*temp_node;

	if (!*begin_list)
	{
		*begin_list = new;
		return ;
	}
	temp_node = *begin_list;
	while ((*begin_list)-> next)
		*begin_list = (*begin_list)-> next;
	(*begin_list)-> next = new;
	*begin_list = temp_node;
}

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*new_list;
	t_list	*new_node;

	new_list = NULL;
	while (size > 0)
	{
		new_node = ft_create_elem(*strs);
		if (!new_node)
			return (NULL);
		my_list_push_back(&new_list, new_node);
		size--;
		strs++;
	}
	return (new_list);
}
