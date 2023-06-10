/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 19:04:41 by seojin            #+#    #+#             */
/*   Updated: 2022/10/01 17:49:08 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

static void	ft_lift_fork(t_profile *profile);
static void	ft_eat_spaghetti(t_profile *profile);

void	ft_eat(t_profile *profile)
{
	ft_lift_fork(profile);
	ft_eat_spaghetti(profile);
}

static void	ft_lift_fork(t_profile *profile)
{
	struct timeval	curr_time;

	sem_wait(profile->status->sem);
	sem_wait(profile->status->public_sem);
	gettimeofday(&curr_time, NULL);
	ft_timestamp(profile->status->start_time, curr_time, \
	LIFT_FORK, profile->status->id);
	sem_post(profile->status->public_sem);
	sem_wait(profile->status->sem);
	sem_wait(profile->status->public_sem);
	gettimeofday(&curr_time, NULL);
	ft_timestamp(profile->status->start_time, curr_time, \
	LIFT_FORK, profile->status->id);
	sem_post(profile->status->public_sem);
}

static void	ft_eat_spaghetti(t_profile *profile)
{
	struct timeval	curr_time;
	struct timeval	start_time;
	long			last_eat_time;
	int				id;

	start_time = profile->status->start_time;
	id = profile->status->id;
	sem_wait(profile->status->public_sem);
	gettimeofday(&curr_time, NULL);
	ft_timestamp(start_time, curr_time, EAT, id);
	sem_post(profile->status->public_sem);
	profile->eat_cnt++;
	sem_wait(profile->private_sem);
	gettimeofday(&profile->last_eat_time, NULL);
	sem_post(profile->private_sem);
	last_eat_time = ft_transform_time(profile->last_eat_time);
	while (ft_eat_time_check(profile, last_eat_time))
		usleep(100);
	sem_post(profile->status->sem);
	sem_post(profile->status->sem);
}
