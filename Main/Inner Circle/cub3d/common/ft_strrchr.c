/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:55:23 by seojin            #+#    #+#             */
/*   Updated: 2022/11/13 14:56:46 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*ft_strrchr(char *str, char c)
{
	int	len;

	len = ft_strlen(str) + 1;
	str = str + ft_strlen(str);
	while (len--)
	{
		if (*str == c)
			return (str);
		str--;
	}
	return (NULL);
}
