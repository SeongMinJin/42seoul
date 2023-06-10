/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeunkim <heeunkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 10:17:53 by heeunkim          #+#    #+#             */
/*   Updated: 2022/04/20 11:12:41 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int x, int y);

int	ft_atoi(char *str)
{
	int	num;
	int	i;

	i = 0;
	num = 0;
	while (str[i] != '\0')
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (num);
}

int	ft_who_ru(char *arr)
{
	int	i;

	i = 0;
	while (arr[i] != '\0')
	{
		if (!('0' <= arr[i] && arr[i] <= '9'))
			return (-1);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	numx;
	int	numy;

	if (argc != 3)
	{
		write(2, "unavailable\n", 12);
		return (-1);
	}
	if (ft_who_ru(argv[1]) != 1)
		return (-1);
	if (ft_who_ru(argv[2]) != 1)
		return (-1);
	numx = ft_atoi(argv[1]);
	numy = ft_atoi(argv[2]);
	rush(numx, numy);
	return (0);
}
