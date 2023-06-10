/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:39:05 by seojin            #+#    #+#             */
/*   Updated: 2022/09/29 00:22:03 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_create_thread(t_status *status);

void	ft_start(t_status *status)
{
	gettimeofday(&status->start_time, NULL);
	ft_create_thread(status);
	ft_monitoring(status, status->attr->num_of_philo);
}

static void	ft_create_thread(t_status *status)
{
	int				i;
	int				num;
	pthread_t		tid;

	i = 0;
	num = status->attr->num_of_philo;
	while (i < num)
	{
		status->philo_arr[i].last_eat_time = status->start_time;
		pthread_create(&tid, NULL, ft_simulation, &status->philo_arr[i]);
		pthread_detach(tid);
		i++;
	}
}
