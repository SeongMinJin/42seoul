/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 12:35:47 by seojin            #+#    #+#             */
/*   Updated: 2022/07/16 14:12:01 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*s;
	size_t	len;

	len = ft_strlen(str);
	s = (char *)malloc((len + 1) * sizeof(char));
	if (!s)
		return (0);
	*(s + len) = 0;
	return ((char *)ft_memmove(s, str, len * sizeof(char)));
}
