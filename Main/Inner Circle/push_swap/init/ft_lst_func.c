/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:20:40 by seojin            #+#    #+#             */
/*   Updated: 2022/08/30 20:08:37 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_new_node(int val)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (0);
	new_node->val = val;
	new_node->a_movement = 0;
	new_node->b_movement = 0;
	new_node->next = 0;
	return (new_node);
}

void	ft_append_back(t_stack **head, t_stack *node)
{
	t_stack	*tmp;

	if (!node)
	{
		ft_free_lst(head);
		ft_exit(ERROR);
	}
	if (!*head)
		*head = node;
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
}

t_stack	*ft_last_node(t_stack *node)
{
	if (!node)
		return (0);
	while (node->next)
		node = node->next;
	return (node);
}

t_stack	*ft_before_last_node(t_stack *node)
{
	if (!node)
		return (0);
	while ((node->next)->next)
		node = node->next;
	return (node);
}

int	ft_lst_len(t_stack *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}
