/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 12:29:25 by seojin            #+#    #+#             */
/*   Updated: 2022/08/11 19:59:02 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static void	ft_putnbr(int n)
{
	long long	nbr;

	nbr = (long long)n;
	if (n < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr < 10)
		write(1, &"0123456789"[nbr], 1);
	else
	{
		ft_putnbr(nbr / 10);
		write(1, &"0123456789"[nbr % 10], 1);
	}
}

void	ft_putpid(pid_t pid)
{
	write(1, "SERVER PID : ", 13);
	ft_putnbr(pid);
	write(1, "\n", 1);
}
