/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 23:53:25 by seojin            #+#    #+#             */
/*   Updated: 2022/05/01 02:02:17 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);

int	check_exist(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *nbr, char *base_from)
{
	int	i;
	int	sign;
	int	number;

	i = 0;
	sign = 1;
	while ((9 <= nbr[i] && nbr[i] <= 13) || nbr[i] == ' ')
		i++;
	while (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			sign *= -1;
		i++;
	}
	number = 0;
	while (check_exist(nbr[i], base_from) != -1)
	{
		number = number * ft_strlen(base_from) + check_exist(nbr[i], base_from);
		i++;
	}
	return (sign * number);
}

int	ft_get_size(long nbr, char *base_to)
{
	int	cnt;

	cnt = 0;
	if (nbr < 0)
	{
		cnt++;
		nbr *= -1;
	}
	else if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= ft_strlen(base_to);
		cnt++;
	}
	return (cnt);
}

char	*ft_itoa_base(long nbr, char *base_to)
{
	char	*str;
	int		size;
	int		i;
	int		minus;

	size = ft_get_size(nbr, base_to);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	str[size] = 0;
	minus = 0;
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
		minus = 1;
	}
	i = 0;
	while (i < size - minus)
	{
		str[size - 1 - i] = base_to[nbr % ft_strlen(base_to)];
		nbr /= ft_strlen(base_to);
		i++;
	}
	return (str);
}
