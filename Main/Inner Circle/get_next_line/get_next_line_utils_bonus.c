/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:30:16 by seojin            #+#    #+#             */
/*   Updated: 2022/07/24 20:43:32 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free_lst(t_lst **lst, int fd)
{
	t_lst	*curr;
	t_lst	*next;

	curr = *lst;
	if (curr->fd == fd)
	{
		(*lst) = (*lst)->next;
		free(curr);
		return ;
	}
	while (curr->next && curr->next->fd != fd)
		curr = curr->next;
	next = curr->next->next;
	free(curr->next);
	curr->next = next;
}

t_lst	*ft_init(int fd, t_lst **lst)
{
	t_lst	*tmp;

	tmp = *lst;
	while (tmp && tmp->fd != fd)
		tmp = tmp->next;
	if (!tmp)
	{
		tmp = (t_lst *)malloc(sizeof(t_lst));
		if (!tmp)
			return (0);
		tmp->backup = 0;
		tmp->fd = fd;
		tmp->next = 0;
		if (*lst == 0)
			*lst = tmp;
		else
		{
			tmp->next = *lst;
			*lst = tmp;
		}
	}
	return (tmp);
}

int	ft_l_b(char *str, int flag)
{
	int	i;

	i = 0;
	if (flag == 0)
	{
		if (!str)
			return (-1);
		while (*(str + i))
		{
			if (*(str + i) == '\n')
				return (i + 1);
			i++;
		}
		return (-1);
	}
	else
	{
		if (!str)
			return (0);
		while (*(str + i))
			i++;
		return (i);
	}
}

int	ft_update_backup(t_lst *tmp, char *src, int i, int size)
{
	char	*str;

	if (!*src)
	{
		if (tmp->backup)
		{
			free(tmp->backup);
			tmp->backup = 0;
		}
		return (1);
	}
	size = ft_l_b(src, 1);
	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (0);
	*(str + size) = 0;
	while (i < size)
	{
		*(str + i) = *(src + i);
		i++;
	}
	if (tmp->backup)
		free(tmp->backup);
	tmp->backup = str;
	return (1);
}

void	ft_bzero(char *buf)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE + 1)
	{
		*(buf + i) = 0;
		i++;
	}
}
