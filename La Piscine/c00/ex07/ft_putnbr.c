/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 19:07:22 by seojin            #+#    #+#             */
/*   Updated: 2022/04/21 11:51:54 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(int nb)
{
	char	digit;
	int		temp;

	if (nb < 10)
	{
		digit = nb + '0';
		write(1, &digit, 1);
		return ;
	}
	else
	{
		temp = nb / 10;
		print(temp);
		digit = (nb % 10) + '0';
		write(1, &digit, 1);
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-", 1);
		write(1, "2147483648", 10);
		return ;
	}
	else if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
		print(nb);
	}
	else
		print(nb);
}

int main()
{
	int n = 4222;
	ft_putnbr(n);
	return 0;
}
