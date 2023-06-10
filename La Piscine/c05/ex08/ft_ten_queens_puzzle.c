/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 20:20:08 by seojin            #+#    #+#             */
/*   Updated: 2022/04/28 14:17:27 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(int chess_board[10][10])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			if (chess_board[i][j] == 1)
			{
				c = j + 48;
				write(1, &c, 1);
			}
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
}

int	check_diagonal(int y_pos, int x_pos, int chess_board[10][10])
{
	int	i;

	i = 0;
	while (y_pos - i >= 0 && x_pos - i >= 0)
	{
		if (chess_board[y_pos - i][x_pos - i] == 1)
			return (0);
		i++;
	}
	i = 0;
	while (y_pos - i >= 0 && x_pos + i <= 9)
	{
		if (chess_board[y_pos - i][x_pos + i] == 1)
			return (0);
		i++;
	}
	return (1);
}

int	check_column(int y_pos, int x_pos, int chess_board[10][10])
{
	int	column;

	column = 0;
	while (column < y_pos)
	{
		if (chess_board[column][x_pos] == 1)
			return (0);
		column++;
	}
	if (check_diagonal(y_pos, x_pos, chess_board))
		return (1);
	return (0);
}

int	put_queens(int y_pos, int chess_board[10][10])
{
	int	x_pos;
	int	i;

	i = 0;
	x_pos = 0;
	if (y_pos == 10)
	{	
		print(chess_board);
		return (1);
	}
	while (x_pos < 10)
	{
		if (check_column(y_pos, x_pos, chess_board))
		{
			chess_board[y_pos][x_pos] = 1;
			i += put_queens(y_pos + 1, chess_board);
		}
		chess_board[y_pos][x_pos] = 0;
		x_pos++;
	}
	return (i);
}

int	ft_ten_queens_puzzle(void)
{
	int	chess_board[10][10];
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			chess_board[i][j] = 0;
			j++;
		}
		i++;
	}
	return (put_queens(0, chess_board));
}
