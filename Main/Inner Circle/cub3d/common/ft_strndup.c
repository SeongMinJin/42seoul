/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 21:57:24 by haryu             #+#    #+#             */
/*   Updated: 2022/11/13 16:18:45 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*ft_strndup(char *str, size_t size)
{
	char	*ret;
	size_t	i;

	ret = malloc(size * sizeof(char));
	if (ret == 0)
		ft_error(MALLOC_ERR);
	i = -1;
	while (++i < size - 1)
		ret[i] = str[i];
	ret[i] = '\0';
	return (ret);
}
