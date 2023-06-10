/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:42:46 by seojin            #+#    #+#             */
/*   Updated: 2022/07/18 18:34:19 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

static int	ft_get_len(void *str)
{
	char *s = (char *)str;
	char *ss = s;
	printf("%s\n", s);
	return (s - ss);
}

t_list	*ft_create_elem(void *data)
{
	t_list	*new_elem;

	int size = ft_get_len(data);
	char *str = (char *)malloc((size+ 1) * sizeof(char));
	memcpy(str, data, size);
	new_elem = (t_list *)malloc(sizeof(t_list));
	if (!new_elem)
		return (NULL);
	new_elem -> data = str;
	new_elem -> next = NULL;
	return (new_elem);
}
