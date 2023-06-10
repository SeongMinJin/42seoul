/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:11:10 by seojin            #+#    #+#             */
/*   Updated: 2022/07/18 07:26:37 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*new_node;
	t_list	*temp_node;

	new_node = ft_create_elem(data);
	if (!new_node || !begin_list)
		return ;
	else if (!*begin_list)
	{
		*begin_list = new_node;
		return ;
	}
	temp_node = *begin_list;
	while ((*begin_list)-> next)
		*begin_list = (*begin_list)-> next;
	(*begin_list)-> next = new_node;
	*begin_list = temp_node;
}
