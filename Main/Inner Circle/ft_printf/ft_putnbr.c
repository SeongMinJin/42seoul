/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 10:29:02 by seojin            #+#    #+#             */
/*   Updated: 2022/07/27 14:13:55 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_unsigned_upper(unsigned int n, int len, unsigned int base)
{
	if (n < base)
	{
		write(1, &("0123456789ABCDEF"[n]), 1);
		return (++len);
	}
	else
	{
		len = ft_putnbr_unsigned_upper(n / base, len + 1, base);
		n = n % base;
		write(1, &("0123456789ABCDEF"[n]), 1);
	}
	return (len);
}

static int	ft_putnbr_unsigned_lower(unsigned int n, int len, unsigned int base)
{
	if (n < base)
	{
		write(1, &("0123456789abcdef"[n]), 1);
		return (++len);
	}
	else
	{
		len = ft_putnbr_unsigned_lower(n / base, len + 1, base);
		n = n % base;
		write(1, &("0123456789abcdef"[n]), 1);
	}
	return (len);
}

static int	ft_putnbr_unsigned(unsigned int n, int len)
{
	if (n < 10)
	{
		write(1, &("0123456789"[n]), 1);
		return (++len);
	}
	else
	{
		len = ft_putnbr_unsigned(n / 10, len + 1);
		n %= 10;
		write(1, &("0123456789"[n]), 1);
	}
	return (len);
}

static int	ft_putnbr_signed(int n, int len)
{
	long long	nbr;

	nbr = (long long)n;
	if (n < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
		len++;
	}
	if (nbr < 10)
	{
		write(1, &("0123456789"[nbr]), 1);
		return (++len);
	}
	else
	{
		len = ft_putnbr_signed(nbr / 10, len + 1);
		nbr %= 10;
		write(1, &("0123456789"[nbr]), 1);
	}
	return (len);
}

int	ft_putnbr(int n, int unsign, char c, unsigned int base)
{
	if (unsign && c == 'x')
		return (ft_putnbr_unsigned_lower((unsigned int)n, 0, base));
	else if (unsign && c == 'X')
		return (ft_putnbr_unsigned_upper((unsigned int)n, 0, base));
	else if (unsign)
		return ((ft_putnbr_unsigned((unsigned int)n, 0)));
	else
		return (ft_putnbr_signed(n, 0));
}
