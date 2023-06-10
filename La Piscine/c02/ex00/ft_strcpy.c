/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 17:54:34 by seojin            #+#    #+#             */
/*   Updated: 2022/04/19 20:12:55 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	if (src[i] == 0)
		dest[0] = 0;
	else
	{
		while (src[i] != 0)
		{
			dest[i] = src[i];
			i++;
		}
	}
	dest[i] = 0;
	return (dest);
}
