/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:53:44 by seojin            #+#    #+#             */
/*   Updated: 2022/04/25 17:30:38 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	len_calculator(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len] != 0)
		len++;
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	i;
	unsigned int	tmp;

	i = 0;
	dest_len = len_calculator(dest);
	src_len = len_calculator(src);
	tmp = dest_len;
	if (dest_len > size)
		return (src_len + size);
	while (src[i] != 0 && size - tmp - i > 1)
	{
		dest[dest_len] = src[i];
		dest_len++;
		i++;
	}
	dest[dest_len] = 0;
	return (tmp + src_len);
}
