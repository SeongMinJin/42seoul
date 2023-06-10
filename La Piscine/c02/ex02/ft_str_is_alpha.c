/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:51:07 by seojin            #+#    #+#             */
/*   Updated: 2022/04/24 01:58:08 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
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
			if (str[size] < 65 || str[size] > 122)
				return (0);
			else if (90 < str[size] && str[size] < 97)
				return (0);
			else
				value = 1;
			size++;
		}
	}
	return (value);
}
