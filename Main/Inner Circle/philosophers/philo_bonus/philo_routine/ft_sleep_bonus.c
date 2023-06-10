/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:57:26 by seojin            #+#    #+#             */
/*   Updated: 2022/09/29 11:36:06 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	ft_sleep(t_profile *profile)
{
	struct timeval	curr_time;
	long			start;

	sem_wait(profile->status->public_sem);
	gettimeofday(&curr_time, NULL);
	ft_timestamp(profile->status->start_time, curr_time, \
	SLEEP, profile->status->id);
	sem_post(profile->status->public_sem);
	start = ft_get_time();
	while (ft_sleep_time_check(profile, start))
		usleep(100);
}
