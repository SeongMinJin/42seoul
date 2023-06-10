/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:55:22 by seojin            #+#    #+#             */
/*   Updated: 2022/11/13 14:56:46 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*ft_strnstr(char *haystack, char *needle, int len)
{
	int	i;
	int	overlap;

	while (*haystack && len--)
	{
		i = 0;
		overlap = 0;
		if (haystack[i] == needle[i] && len + 1 >= ft_strlen(needle))
		{
			while (haystack[i] && haystack[i] == needle[i])
			{
				if (needle[i] == needle[i + 1])
					overlap++;
				i++;
			}
			if (!needle[i])
				return (haystack);
		}
		else
			i++;
		haystack = haystack + i - overlap;
	}
	return (NULL);
}
