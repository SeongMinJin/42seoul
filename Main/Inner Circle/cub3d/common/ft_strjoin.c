/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 21:53:27 by haryu             #+#    #+#             */
/*   Updated: 2022/11/13 16:18:13 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static char	*ft_write_str(char *str, char *src1, char *src2)
{
	int	i;

	i = 0;
	while (i < ft_strlen(src1))
	{
		if (!*src1)
			continue ;
		*(str + i) = *(src1 + i);
		i++;
	}
	while (i < ft_strlen(src1) + ft_strlen(src2))
	{
		if (!*src2)
			continue ;
		*(str + i) = *(src2 + (i - ft_strlen(src1)));
		i++;
	}
	*(str + i) = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*ret;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ret = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (ret == NULL)
		return (NULL);
	ret = ft_write_str(ret, s1, s2);
	return (ret);
}
