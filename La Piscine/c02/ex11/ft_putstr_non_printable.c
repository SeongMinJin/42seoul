/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:50:13 by seojin            #+#    #+#             */
/*   Updated: 2022/05/04 18:12:48 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int				index;
	unsigned char	*k;

	k = (unsigned char *)str;
	index = 0;
	while (k[index])
	{
		if (32 <= k[index] && k[index] <= 126)
			write(1, &k[index], 1);
		else
		{
			write(1, "\\", 1);
			write(1, &"0123456789abcdef"[k[index] / 16], 1);
			write(1, &"0123456789abcdef"[k[index] % 16], 1);
		}
		index++;
	}
}
