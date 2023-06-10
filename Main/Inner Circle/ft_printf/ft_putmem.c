/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:08:45 by seojin            #+#    #+#             */
/*   Updated: 2022/07/27 14:19:45 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_mem(unsigned long n, int len)
{
	long	c;

	if (n < 16)
	{
		write(1, &("0123456789abcdef"[n]), 1);
		return (++len);
	}
	else
	{
		len = ft_putnbr_mem(n / 16, len + 1);
		c = n % 16;
		write(1, &("0123456789abcdef"[c]), 1);
	}
	return (len);
}

int	ft_putmem(void *p)
{
	unsigned long	n;

	n = (unsigned long)p;
	write(1, "0x", 2);
	return (2 + ft_putnbr_mem(n, 0));
}
