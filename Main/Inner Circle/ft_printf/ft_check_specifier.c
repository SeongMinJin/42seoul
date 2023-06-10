/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_specifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 07:55:12 by seojin            #+#    #+#             */
/*   Updated: 2022/07/27 14:17:53 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_specifier(const char c, va_list pa)
{
	if (c == 'c')
		return (ft_putchar(va_arg(pa, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(pa, char *)));
	else if (c == 'd' || c == 'i' || c == 'u')
		return (ft_putnbr(va_arg(pa, int), c == 'u', c, 10));
	else if (c == 'x' || c == 'X')
		return (ft_putnbr(va_arg(pa, int), 1, c, 16));
	else if (c == 'p')
		return (ft_putmem(va_arg(pa, void *)));
	else if (c == '%')
		return (ft_putchar('%'));
	else
		return (0);
}
