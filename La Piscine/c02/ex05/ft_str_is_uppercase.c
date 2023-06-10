/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:01:01 by seojin            #+#    #+#             */
/*   Updated: 2022/04/19 20:22:54 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	size;
	int	value;

	size = 0;
	if (str[size] == 0)
		value = 1;
	else
	{
		while (str[size] != 0)
		{
			if (str[size] < 65 || str[size] > 90)
				return (0);
			else
				value = 1;
			size++;
		}
	}
	return (value);
}
