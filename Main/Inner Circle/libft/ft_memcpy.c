/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:14:03 by seojin            #+#    #+#             */
/*   Updated: 2022/07/13 07:12:28 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*t_dst;
	unsigned char	*t_src;

	if (!dst && !src)
		return (0);
	t_dst = (unsigned char *)dst;
	t_src = (unsigned char *)src;
	while (n--)
		*t_dst++ = *t_src++;
	return (dst);
}
