/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 09:16:25 by seojin            #+#    #+#             */
/*   Updated: 2022/07/27 14:23:26 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int		len;
	va_list	pa;

	len = 0;
	va_start(pa, s);
	while (*s)
	{
		if (*s == '%')
		{
			len += ft_check_specifier(*++s, pa);
			s++;
		}
		else
		{
			len += ft_putchar(*s);
			s++;
		}
	}
	va_end(pa);
	return (len);
}
