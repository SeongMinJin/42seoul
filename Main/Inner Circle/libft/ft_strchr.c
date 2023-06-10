/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:47:27 by seojin            #+#    #+#             */
/*   Updated: 2022/07/16 10:35:40 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	if ((char)c == 0)
		return ((char *)(str + ft_strlen(str)));
	while (*str)
		if (*str++ == (char)c)
			return ((char *)(str - 1));
	return (0);
}
