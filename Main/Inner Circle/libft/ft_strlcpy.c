/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:00:10 by seojin            #+#    #+#             */
/*   Updated: 2022/07/16 09:30:06 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	const char	*t_src;

	t_src = src;
	if (dstsize)
	{
		while (dstsize-- > 1 && *t_src)
			*dst++ = *(char *)t_src++;
		*dst = 0;
	}
	return (ft_strlen(src));
}
