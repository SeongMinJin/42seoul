/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:01:01 by seojin            #+#    #+#             */
/*   Updated: 2022/04/19 20:28:35 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
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
			if (str[size] < 32 || str[size] == 127)
				return (0);
			else
				value = 1;
			size++;
		}
	}
	return (value);
}
