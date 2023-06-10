/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 23:53:39 by seojin            #+#    #+#             */
/*   Updated: 2022/05/01 03:45:46 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_atoi_base(char *nbr, char *base_from);
char	*ft_itoa_base(long nbr, char *base_to);

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	check_valid_base(char *base)
{
	int	i;
	int	init;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] == ' ')
			return (0);
		else if (9 <= base[i] && base[i] <= 13)
			return (0);
		init = 0;
		while (init < i)
		{
			if (base[init] == base[i])
				return (0);
			init++;
		}
		i++;
	}
	return (1);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		number;
	char	*str;

	if (check_valid_base(base_from) && check_valid_base(base_to))
	{
		number = ft_atoi_base(nbr, base_from);
		str = ft_itoa_base(number, base_to);
		return (str);
	}
	else
		return (0);
}
