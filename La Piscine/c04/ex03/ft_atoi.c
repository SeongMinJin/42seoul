/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 22:30:47 by seojin            #+#    #+#             */
/*   Updated: 2022/04/26 17:41:16 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	index;
	int	minus;
	int	number;

	minus = 1;
	index = 0;
	number = 0;
	while ((9 <= str[index] && str[index] <= 13) || str[index] == ' ')
		index++;
	while (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			minus *= -1;
		index++;
	}
	while ('0' <= str[index] && str[index] <= '9')
	{
		number = number * 10 + str[index] - 48;
		index++;
	}
	return (minus * number);
}
