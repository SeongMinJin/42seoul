/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:36:06 by seojin            #+#    #+#             */
/*   Updated: 2022/07/18 18:58:34 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	overlap;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len--)
	{
		i = 0;
		overlap = 0;
		if (*(haystack + i) == *(needle + i) && len + 1 >= ft_strlen(needle))
		{
			while (*(haystack + i) && *(haystack + i) == *(needle + i))
			{
				if (*(needle + i) == *(needle + i + 1))
					overlap++;
				i++;
			}
			if (!*(needle + i))
				return ((char *)haystack);
		}
		else
			i++;
		haystack = haystack + i - overlap;
	}
	return (0);
}
