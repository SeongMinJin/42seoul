/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 00:17:35 by seojin            #+#    #+#             */
/*   Updated: 2022/04/26 18:46:16 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

void	ft_putnbr(long long nbr, char *base)
{
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
		ft_putnbr(nbr, base);
	}
	else if (nbr < ft_strlen(base))
		write(1, &base[nbr], 1);
	else
	{
		ft_putnbr((nbr / ft_strlen(base)), base);
		write(1, &base[nbr % ft_strlen(base)], 1);
	}
}

int	check_valid_base(char *base)
{
	int	index;
	int	size;
	int	init;

	index = 0;
	size = ft_strlen(base);
	if (size <= 1)
		return (0);
	while (base[index] != 0)
	{
		if (base[index] == '-' || base[index] == '+')
			return (0);
		init = 0;
		while (init < index)
		{
			if (base[init] == base[index])
				return (0);
			init++;
		}
		index++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (check_valid_base(base))
		ft_putnbr(nbr, base);
}
