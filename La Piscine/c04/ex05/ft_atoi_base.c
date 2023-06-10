/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 02:29:49 by seojin            #+#    #+#             */
/*   Updated: 2022/04/26 18:43:17 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int	len;
	int	index;
	int	init;

	len = ft_strlen(base);
	if (len <= 1)
		return (0);
	index = 0;
	while (base[index])
	{
		if (base[index] == '-' || base[index] == '+' || base[index] == ' ')
			return (0);
		else if (9 <= base[index] && base[index] <= 13)
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

int	check_exist(char c, char *base)
{
	int	index;

	index = 0;
	while (base[index])
	{
		if (base[index] == c)
			return (index);
		index++;
	}
	return (-1);
}

int	check_minus(char *str)
{
	int	index;
	int	minus;

	index = 0;
	minus = 1;
	while (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			minus *= -1;
		index++;
	}
	return (minus);
}

int	ft_atoi_base(char *str, char *base)
{
	int	idx;
	int	minus;
	int	number;
	int	blen;

	idx = 0;
	number = 0;
	blen = ft_strlen(base);
	if (check_valid_base(base))
	{
		while ((9 <= str[idx] && str[idx] <= 13) || str[idx] == ' ')
			idx++;
		minus = check_minus(&str[idx]);
		while (str[idx] == '+' || str[idx] == '-')
			idx++;
		while (check_exist(str[idx], base) != -1)
		{
			number = number * blen + check_exist(str[idx], base);
			idx++;
		}
		return (minus * number);
	}
	return (0);
}
