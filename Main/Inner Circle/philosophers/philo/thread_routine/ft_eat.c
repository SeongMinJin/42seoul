/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 19:04:41 by seojin            #+#    #+#             */
/*   Updated: 2023/02/27 14:40:58 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	ft_lift_fork(t_philo_profile *profile, int id);
static void	ft_eat_spaghetti(t_philo_profile *profile, int id);

void	ft_eat(t_philo_profile *profile, int id)
{
	ft_lift_fork(profile, id);
	ft_eat_spaghetti(profile, id);
}

static void	ft_lift_fork(t_philo_profile *profile, int id)
{
	struct timeval	curr_time;

	ft_lock(profile->fork1);
	*profile->fork1_usage += 1;
	ft_lock(profile->status->public_mutex);
	gettimeofday(&curr_time, NULL);
	ft_timestamp(profile->status->start_time, curr_time, LIFT_FORK, id);
	ft_unlock(profile->status->public_mutex);
	ft_lock(profile->fork2);
	*profile->fork2_usage += 1;
	ft_lock(profile->status->public_mutex);
	gettimeofday(&curr_time, NULL);
	ft_timestamp(profile->status->start_time, curr_time, LIFT_FORK, id);
	ft_unlock(profile->status->public_mutex);
}

static void	ft_eat_spaghetti(t_philo_profile *profile, int id)
{
	struct timeval	curr_time;
	long			last_eat_time;

	gettimeofday(&curr_time, NULL);
	ft_lock(profile->status->public_mutex);
	ft_timestamp(profile->status->start_time, curr_time, EAT, id);
	ft_unlock(profile->status->public_mutex);
	profile->eat_cnt++;
	ft_lock(&profile->status->guard_mutex_arr[id]);
	gettimeofday(&profile->last_eat_time, NULL);
	last_eat_time = ft_transform_time(profile->last_eat_time);
	ft_unlock(&profile->status->guard_mutex_arr[id]);
	while (ft_eat_time_check(profile, last_eat_time))
		usleep(100);
	ft_unlock(profile->fork1);
	ft_unlock(profile->fork2);
}
