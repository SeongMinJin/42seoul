/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:26:15 by seojin            #+#    #+#             */
/*   Updated: 2022/05/04 18:13:04 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(unsigned long long n, int flag)
{
	if (flag == 0)
		write(1, &"0123456789abcdef"[n], 1);
	else
	{
		ft_putnbr(n / 16, flag - 1);
		write(1, &"0123456789abcdef"[n % 16], 1);
	}
}

void	print_tail(void *addr)
{
	unsigned int	i;
	unsigned char	*str;

	str = (unsigned char *)addr;
	i = 0;
	while (i < 16 && *str)
	{
		if (32 <= *str && *str <= 126)
			write(1, str, 1);
		else
			write(1, ".", 1);
		i++;
		str++;
	}
}

void	print_body(void *addr)
{
	unsigned int	i;
	unsigned char	*str;

	str = (unsigned char *)addr;
	i = 0;
	while (i < 16 && str[i])
	{
		write(1, &"0123456789abcdef"[str[i] / 16], 1);
		write(1, &"0123456789abcdef"[str[i] % 16], 1);
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
	while (i < 16)
	{
		write(1, "  ", 2);
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
}

void	print_header(void *addr)
{
	unsigned long long	k;

	k = (unsigned long long)addr;
	ft_putnbr(k, 15);
	write(1, ": ", 2);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		print_header(addr);
		print_body(addr);
		print_tail(addr);
		write(1, "\n", 1);
		addr += 16;
		i += 16;
	}
	return (addr);
}
