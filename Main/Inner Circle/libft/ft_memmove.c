/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:15:28 by seojin            #+#    #+#             */
/*   Updated: 2022/07/16 13:50:16 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*t_dst;
	unsigned char	*t_src;

	if (!dst && !src)
		return (0);
	t_dst = (unsigned char *)dst;
	t_src = (unsigned char *)src;
	if (t_dst > t_src)
	{
		t_dst += len;
		t_src += len;
		while (len--)
			*--t_dst = *--t_src;
	}
	else
		while (len--)
			*t_dst++ = *t_src++;
	return (dst);
}
