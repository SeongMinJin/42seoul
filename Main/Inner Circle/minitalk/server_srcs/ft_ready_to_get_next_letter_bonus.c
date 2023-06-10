/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ready_to_get_next_letter_bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:38:57 by seojin            #+#    #+#             */
/*   Updated: 2022/08/12 10:45:42 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk_bonus.h"

void	ft_ready_to_get_next_letter(t_info *info)
{
	unsigned char	*str;

	if (info->str == EMPTY)
	{
		info->str = (unsigned char *)malloc(2 * sizeof(unsigned char));
		if (!info->str)
			return (ft_null_guard(info));
		(info->str)[0] = info->c;
		(info->str)[1] = 0;
		ft_clean_server(info);
		info->byte++;
		return ;
	}
	str = (unsigned char *)malloc((2 + info->byte) * sizeof(unsigned char));
	if (!str)
		return (ft_null_guard(info));
	ft_memmove(str, info->str, info->byte);
	str[info->byte] = info->c;
	str[info->byte + 1] = 0;
	free(info->str);
	info->str = str;
	ft_clean_server(info);
	info->byte++;
}
