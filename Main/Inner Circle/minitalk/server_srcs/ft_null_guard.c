/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_null_guard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 16:09:58 by seojin            #+#    #+#             */
/*   Updated: 2022/08/11 20:04:36 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static void	ft_send_malloc_error_sig(pid_t client, size_t timer)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		kill(client, SIGUSR1);
		usleep(timer);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		kill(client, SIGUSR2);
		usleep(timer);
		i++;
	}
}

void	ft_null_guard(t_info *info)
{
	ft_send_malloc_error_sig(info->pid, info->timer);
	if (info->str)
		free(info->str);
	ft_init_info(info);
	return ;
}
