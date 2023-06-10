/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 13:51:31 by seojin            #+#    #+#             */
/*   Updated: 2022/05/04 18:03:30 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_2(long long n)
{
	char	num;

	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n < 10)
	{
		num = n + '0';
		write(1, &num, 1);
	}
	else
	{
		ft_putnbr_2(n / 10);
		num = (n % 10) + '0';
		write(1, &num, 1);
	}
}

void	ft_putnbr(long long n)
{
	ft_putnbr_2(n);
	write(1, "\n", 1);
}
