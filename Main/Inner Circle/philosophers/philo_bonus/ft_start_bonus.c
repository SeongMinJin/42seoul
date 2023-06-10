/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:51:50 by seojin            #+#    #+#             */
/*   Updated: 2022/09/29 11:56:44 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	ft_kill(t_status *status, pid_t *pid_arr);

void	ft_start(t_status *status)
{
	int		i;
	pid_t	pid;
	pid_t	*pid_arr;

	i = 0;
	pid_arr = (pid_t *)malloc(status->num_of_philo * sizeof(pid_t));
	gettimeofday(&status->start_time, NULL);
	if (!pid_arr)
		return ;
	while (i < status->num_of_philo)
	{
		status->id++;
		pid = fork();
		if (pid == 0)
			ft_philo_routine(status);
		pid_arr[i] = pid;
		i++;
	}
	waitpid (-1, NULL, 0);
	ft_kill(status, pid_arr);
}

static void	ft_kill(t_status *status, pid_t *pid_arr)
{
	int	i;
	int	num;

	i = 0;
	num = status->num_of_philo;
	while (i < num)
	{
		kill(pid_arr[i], SIGINT);
		i++;
	}
	free(pid_arr);
}
