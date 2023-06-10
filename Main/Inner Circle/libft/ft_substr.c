/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:10:52 by seojin            #+#    #+#             */
/*   Updated: 2022/07/15 07:49:55 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	size;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start >= s_len)
		size = 0;
	else if (s_len - start < len)
		size = s_len - start;
	else
		size = len;
	substr = (char *)malloc((size + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	*(substr + size) = 0;
	return (ft_memmove(substr, s + start, size));
}
