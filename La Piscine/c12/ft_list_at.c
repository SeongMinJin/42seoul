/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:25:55 by seojin            #+#    #+#             */
/*   Updated: 2022/07/16 16:36:43 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	while (nbr && begin_list -> next != NULL)
	{
		begin_list = begin_list -> next;
		nbr--;
	}
	if (nbr)
		return (NULL);
	return (begin_list);
}
