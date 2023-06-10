/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:52:48 by seojin            #+#    #+#             */
/*   Updated: 2022/04/19 20:18:20 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	size;
	int	value;

	size = 0;
	if (str[size] == 0)
		return (1);
	else
	{
		while (str[size] != 0)
		{
			if (str[size] < '0' || str[size] > '9')
			{
				return (0);
			}
			else
				value = 1;
			size++;
		}
	}
	return (value);
}
