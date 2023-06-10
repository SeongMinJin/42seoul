/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:47:29 by seojin            #+#    #+#             */
/*   Updated: 2022/04/27 16:09:20 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	num;

	num = 1;
	if (nb > 0)
	{
		while (nb > 0)
		{
			num = num * nb;
			nb--;
		}
		return (num);
	}
	else if (nb < 0)
		return (0);
	else
		return (1);
}
