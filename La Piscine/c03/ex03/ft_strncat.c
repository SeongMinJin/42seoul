/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 00:35:40 by seojin            #+#    #+#             */
/*   Updated: 2022/04/21 15:59:28 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int	dest_index;
	int	src_index;

	dest_index = 0;
	src_index = 0;
	while (dest[dest_index] != 0)
		dest_index++;
	while (nb > 0 && src[src_index] != 0)
	{
		dest[dest_index] = src[src_index];
		dest_index++;
		src_index++;
		nb--;
	}
	dest[dest_index] = 0;
	return (dest);
}
