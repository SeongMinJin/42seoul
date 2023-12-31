/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:28:32 by seojin            #+#    #+#             */
/*   Updated: 2022/04/19 20:30:17 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	size;

	size = 0;
	while (str[size] != 0)
	{
		if (97 <= str[size] && str[size] <= 122)
			str[size] -= 32;
		size++;
	}
	return (str);
}
