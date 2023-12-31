/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:43:39 by seojin            #+#    #+#             */
/*   Updated: 2022/07/18 18:23:58 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}	t_list;

t_list	*ft_create_elem(void *data);
t_list	*ft_list_at(t_list *begin_list, unsigned int nbr);
t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)());
t_list	*ft_list_last(t_list *begin_list);
t_list	*ft_list_push_strs(int size, char **strs);

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *));
void	ft_list_foreach(t_list *begin_list, void (*f)(void *));
void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *), \
		void *data_ref, int (*cmp)());
void	ft_list_merge(t_list **begin_list1, t_list *begin_list2);
void	ft_list_push_back(t_list **begin_list, void *data);
void	ft_list_push_front(t_list **begin_list, void *data);
void	ft_sorted_list_merge(t_list **begin_list1, \
		t_list *begin_list2, int (*cmp)());
void	ft_list_remove_if(t_list **begin_list, void \
		*data_ref, int (*cmp)(), void (*free_fct)(void *));
void	ft_list_reverse(t_list **list);
void	ft_list_reverse_fun(t_list *begin_list);
void	ft_list_sort(t_list **list, int (*cmp)());
void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)());

int		ft_list_size(t_list *begin_list);

#endif
