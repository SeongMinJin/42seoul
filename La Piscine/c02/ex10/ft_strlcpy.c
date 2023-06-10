/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 21:17:04 by seojin            #+#    #+#             */
/*   Updated: 2022/04/19 23:02:45 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int	src_size;
	int	index;
	int	temp;

	src_size = 0;
	index = 0;
	while (src[src_size] != 0)
		src_size++;
	temp = src_size;
	if (size == 0)
		return (src_size);
	else if (src_size == 0)
	{
		dest[0] = 0;
		return (src_size);
	}
	while (size > 1 && temp > 0)
	{
		dest[index] = src[index];
		index++;
		size--;
		temp--;
	}
	dest[index] = 0;
	return (src_size);
}
