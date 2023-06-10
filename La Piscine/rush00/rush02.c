/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeunkim <heeunkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 13:02:52 by heeunkim          #+#    #+#             */
/*   Updated: 2022/04/16 13:26:39 by heeunkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_line(int n, char a, char b, char c)
{
	int	x;

	ft_putchar(a);
	if (n == 1)
		return ;
	else
	{
		x = 1;
		while (x < n - 1)
		{
			ft_putchar(b);
			x++;
		}
		ft_putchar(c);
	}
}

void	rush(int x, int y)
{
	int	cy;

	if (x <= 0 || y <= 0)
		return ;
	cy = 1;
	while (cy <= y)
	{
		if (cy == 1)
			print_line(x, 'A', 'B', 'A');
		else if (2 <= cy && cy < y)
			print_line(x, 'B', ' ', 'B');
		else
			print_line(x, 'C', 'B', 'C');
		ft_putchar('\n');
		cy++;
	}
}
