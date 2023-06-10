/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:57:42 by seojin            #+#    #+#             */
/*   Updated: 2022/07/16 14:15:31 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*head;
	char	*tail;
	char	*str;

	head = (char *)s1;
	tail = (char *)s1 + ft_strlen(s1) - 1;
	while (ft_strchr(set, *head) && *head)
		head++;
	while (ft_strchr(set, *tail))
	{
		tail--;
		if (head > tail)
			break ;
	}
	if (head > tail)
		str = (char *)ft_calloc(1, sizeof(char));
	else
		str = (char *)malloc((tail - head + 2)* sizeof(char));
	if (!str)
		return (0);
	*(str + (tail - head + 1)) = 0;
	if (head > tail)
		return (str);
	return (ft_memmove(str, head, tail - head + 1));
}
