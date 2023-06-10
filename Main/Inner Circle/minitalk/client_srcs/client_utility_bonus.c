/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utility_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:22:29 by seojin            #+#    #+#             */
/*   Updated: 2022/08/12 10:45:11 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk_bonus.h"

void	ft_next_step(t_info *status, unsigned char *curr, int *i)
{
	*curr = *curr << 1;
	*i += 1;
	usleep(status->timer);
}

void	ft_send_signal(unsigned char curr, pid_t pid)
{
	if ((curr & 128) == 128)
		kill(pid, SIGUSR2);
	else
		kill(pid, SIGUSR1);
}

void	ft_init_status(t_info *status, pid_t pid, char *str)
{
	status->str = (unsigned char *)str;
	status->c = 0;
	status->bit = 0;
	status->byte = 0;
	status->timer = 100;
	status->pid = pid;
}

void	ft_exit(int flag)
{
	if (flag == ARGC_FAIL)
		write(1, "__ARGC_FAIL__\n", 14);
	else if (flag == INVALID_PID)
		write(1, "__INVALID_PID__\n", 16);
	else if (flag == MALLOC_ERROR)
		write(1, "__MALLOC_ERROR__\n", 17);
	exit(EXIT_SUCCESS);
}
