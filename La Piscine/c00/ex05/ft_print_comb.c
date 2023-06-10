/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:18:36 by seojin            #+#    #+#             */
/*   Updated: 2022/04/21 11:45:05 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char a, char b, char c)
{
	char	spliter[3];

	spliter[0] = ',';
	spliter[1] = ' ';
	if (a == '7' && b == '8' && c == '9')
	{
		write(1, &a, 1);
		write(1, &b, 1);
		write(1, &c, 1);
	}
	else
	{
		write(1, &a, 1);
		write(1, &b, 1);
		write(1, &c, 1);
		write(1, &spliter[0], 1);
		write(1, &spliter[1], 1);
	}
}

void	ft_print_comb(void)
{
	char	number[3];

	number[0] = '0';
	number[1] = '1';
	number[2] = '2';
	while (number[0] < 56)
	{
		print(number[0], number[1], number[2]);
		if (number[2] == '9')
		{
			number[1] += 1;
			number[2] = number[1] + 1;
		}
		else
		{
			number[2]++;
		}
		if (number[1] == '9')
		{
			number[0] += 1;
			number[1] = number[0] + 1;
			number[2] = number[1] + 1;
		}
	}
}

int main()
{
	ft_print_comb();
	return 0;
}
