/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:57:26 by seojin            #+#    #+#             */
/*   Updated: 2022/09/29 11:28:26 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_sleep(t_philo_profile *profile, int id)
{
	struct timeval	curr_time;
	long			start;

	ft_lock(profile->status->public_mutex);
	gettimeofday(&curr_time, NULL);
	ft_timestamp(profile->status->start_time, curr_time, SLEEP, id);
	ft_unlock(profile->status->public_mutex);
	start = ft_get_time();
	while (ft_sleep_time_check(profile, start))
		usleep(100);
}
