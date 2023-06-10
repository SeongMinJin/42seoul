/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:40:48 by seojin            #+#    #+#             */
/*   Updated: 2022/04/24 01:35:31 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_front_char(char c)
{
	if (c < '0' || ('9' < c && c < 'A'))
		return (1);
	else if (('Z' < c && c < 'a') || c > 'z')
		return (1);
	else
		return (0);
}

int	check_upper(char c)
{
	if (('0' <= c && c <= '9') || ('A' <= c && c <= 'Z'))
		return (1);
	else if ('a' <= c && c <= 'z')
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	size;

	size = 0;
	if ('a' <= str[size] && str[size] <= 'z')
		str[size] -= 32;
	size++;
	while (str[size] != 0)
	{
		if (check_front_char(str[size - 1]))
		{
			if ('a' <= str[size] && str[size] <= 'z')
				str[size] -= 32;
		}
		else if (check_upper(str[size - 1]))
		{
			if ('A' <= str[size] && str[size] <= 'Z')
				str[size] += 32;
		}
		size++;
	}
	return (str);
}
