/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 21:22:42 by seojin            #+#    #+#             */
/*   Updated: 2022/04/21 12:02:37 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char *arr, int size_fix)
{
	int		i;
	char	spliter[2];

	spliter[0] = ',';
	spliter[1] = ' ';
	i = 0;
	while (arr[i] != 0)
	{
		write(1, &arr[i], 1);
		i++;
	}
	if (arr[0] == 58 - size_fix)
		return ;
	write(1, spliter, 2);
}

void	action(char *arr, int size, int flag, int size_fix)
{
	int	temp;

	if (flag == size_fix)
	{
		print(arr, size_fix);
		arr[flag - 1]++;
		return ;
	}
	else
	{
		while (arr[flag] < 59 - size)
		{
			if (arr[size_fix - 1] == ':')
			{
				temp = flag;
				arr[temp]++;
				while (temp < size_fix - 1)
				{
					arr[temp + 1] = arr[temp] + 1;
					temp++;
				}
			}
			action(arr, (size - 1), (flag + 1), size_fix);
		}
	}
}

void	ft_print_combn(int n)
{
	char	arr[10];
	int		size;
	int		size_fix;
	int		flag;

	size = -1;
	flag = 0;
	if (0 < n && n < 10)
		while (size++ < n - 1)
			arr[size] = '0' + size;
	else
		return ;
	size_fix = size;
	action(arr, size, flag, size_fix);
}

int main()
{
	int n = 4;

	ft_print_combn(n);
	return 0;
}
