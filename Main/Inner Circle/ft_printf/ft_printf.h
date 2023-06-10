/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 10:19:17 by seojin            #+#    #+#             */
/*   Updated: 2022/07/27 14:26:03 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	ft_check_specifier(const char c, va_list pa);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int n, int unsign, char c, unsigned int base);
int	ft_putmem(void *p);

#endif