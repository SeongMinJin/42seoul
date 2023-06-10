/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_meal_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:02:07 by seojin            #+#    #+#             */
/*   Updated: 2022/09/29 11:51:10 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	ft_check_meal(t_profile *profile, struct timeval curr_time)
{
	int				usec;
	long			sec;

	sem_wait(profile->private_sem);
	sec = (curr_time.tv_sec - \
	profile->last_eat_time.tv_sec) * 1000;
	usec = (curr_time.tv_usec - profile->last_eat_time.tv_usec) / 1000;
	sem_post(profile->private_sem);
	if (sec + usec > profile->status->time_to_die)
	{
		sem_wait(profile->status->public_sem);
		ft_timestamp(profile->status->start_time, curr_time, \
		DIE, profile->status->id);
		exit(0);
	}
}
