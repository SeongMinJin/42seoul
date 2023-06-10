/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:59:55 by seojin            #+#    #+#             */
/*   Updated: 2022/04/21 17:25:55 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(int nb)
{
	char	quotient;
	char	remainder;

	if (nb < 10)
	{
		quotient = nb + '0';
		write(1, &quotient, 1);
		return ;
	}
	else
	{
		remainder = (nb % 10) + '0';
		nb /= 10;
		print(nb);
		write(1, &remainder, 1);
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb == 0)
		write(1, "0", 1);
	else if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
		print(nb);
	}
	else
		print(nb);
}
