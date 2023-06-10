/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 16:29:06 by seojin            #+#    #+#             */
/*   Updated: 2022/08/12 10:45:32 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk_bonus.h"

static void	ft_confirm_sig(pid_t client, size_t timer)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		kill(client, SIGUSR2);
		usleep(timer);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		kill(client, SIGUSR1);
		usleep(timer);
		i++;
	}
}

void	ft_print(t_info *info)
{
	write(1, info->str, info->byte);
	write(1, "\nDONE\n", 6);
	ft_confirm_sig(info->pid, info->timer);
	free(info->str);
}
