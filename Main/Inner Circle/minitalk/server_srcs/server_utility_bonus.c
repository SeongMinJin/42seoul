/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utility_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:43:02 by seojin            #+#    #+#             */
/*   Updated: 2022/08/12 10:46:00 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk_bonus.h"

void	ft_accumulate_bit(t_info *info, int bit)
{
	info->c += bit;
	if (info->bit != 7)
		info->c = (info->c) << 1;
	info->bit++;
}

void	ft_clean_server(t_info *info)
{
	info->c = 0;
	info->bit = 0;
}

void	ft_init_info(t_info *info)
{
	info->str = NULL;
	info->c = 0;
	info->stop = 0;
	info->bit = 0;
	info->byte = 0;
	info->timer = 50;
	info->pid = EMPTY;
}

void	ft_memmove(unsigned char *dst, unsigned char *src, size_t len)
{
	while (len--)
		*dst++ = *src++;
}
