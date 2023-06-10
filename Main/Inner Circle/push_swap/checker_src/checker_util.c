/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:38:15 by seojin            #+#    #+#             */
/*   Updated: 2022/08/31 20:58:55 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strlen(char *str)
{
	char	*tmp;

	tmp = str;
	while (*tmp)
		tmp++;
	return (tmp - str);
}

char	*ft_glue(char *str, char buf)
{
	char	*new;

	if (!str)
	{
		str = (char *)malloc(2 * sizeof(char));
		if (!str)
			return (0);
		str[0] = buf;
		str[1] = 0;
		return (str);
	}
	new = (char *)malloc((ft_strlen(str) + 2) * sizeof(char));
	if (!new)
	{
		free(str);
		return (0);
	}
	ft_memmove(new, str);
	new[ft_strlen(str)] = buf;
	new[ft_strlen(str) + 1] = 0;
	free(str);
	return (new);
}

int	cmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

void	ft_memmove(char *dst, char *src)
{
	while (*src)
		*dst++ = *src++;
}

void	ft_error(t_stack **a, t_stack **b)
{
	ft_free_lst(a);
	ft_free_lst(b);
	ft_exit(ERROR);
}
