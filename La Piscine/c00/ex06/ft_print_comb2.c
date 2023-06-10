/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:11:39 by seojin            #+#    #+#             */
/*   Updated: 2022/04/21 11:48:40 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char first_0, char first_1, char second_0, char second_1)
{
	char	spliter[2];

	spliter[0] = ',';
	spliter[1] = ' ';
	if (first_0 == '9' && first_1 == '8' && second_0 == '9' && second_1 == '9')
	{
		write(1, &first_0, 1);
		write(1, &first_1, 1);
		write(1, &spliter[1], 1);
		write(1, &second_0, 1);
		write(1, &second_1, 1);
	}
	else
	{
		write(1, &first_0, 1);
		write(1, &first_1, 1);
		write(1, &spliter[1], 1);
		write(1, &second_0, 1);
		write(1, &second_1, 1);
		write(1, &spliter, 2);
	}
}

void	print_second(char first_0, char first_1, char second_0, char second_1)
{
	char	first[2];
	char	second[2];

	first[0] = first_0;
	first[1] = first_1;
	second[0] = second_0;
	second[1] = second_1 - 1;
	while (second[0] + second[1] != 114)
	{
		if (second[1] == '9')
		{
			second[0]++;
			second[1] = '0';
		}
		else
			second[1]++;
		print(first[0], first[1], second[0], second[1]);
	}
}

void	ft_print_comb2(void)
{
	char	first[2];
	char	second[2];

	first[0] = '0';
	first[1] = '/';
	second[0] = '0';
	second[1] = '0';
	while (second[0] + second[1] < 114)
	{
		if (second[1] == '9')
		{
			second[0]++;
			second[1] = '0';
		}
		else
			second[1]++;
		if (first[1] == '9')
		{
			first[0]++;
			first[1] = '0';
		}
		else
			first[1]++;
		print_second(first[0], first[1], second[0], second[1]);
	}
}

int main()
{
	ft_print_comb2();
	return 0;
}
