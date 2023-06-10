/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:55:07 by seojin            #+#    #+#             */
/*   Updated: 2022/11/13 14:56:47 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*ft_strdup(char *str)
{
	char	*s;
	int		len;
	int		idx;

	len = ft_strlen(str);
	s = (char *)malloc((len + 1) * sizeof(char));
	if (!s)
		ft_error(MALLOC_ERR);
	s[len] = 0;
	idx = 0;
	while (*str)
		s[idx++] = *str++;
	return (s);
}
