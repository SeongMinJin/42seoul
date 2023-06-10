/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_meal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:02:07 by seojin            #+#    #+#             */
/*   Updated: 2022/09/28 23:47:25 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_meal(t_philo_profile *profile, \
struct timeval curr_time, int id)
{
	int				usec;
	long			sec;

	ft_lock(&profile->status->guard_mutex_arr[id]);
	sec = (curr_time.tv_sec - \
	profile->last_eat_time.tv_sec) * 1000;
	usec = (curr_time.tv_usec - profile->last_eat_time.tv_usec) / 1000;
	ft_unlock(&profile->status->guard_mutex_arr[id]);
	if (sec + usec > profile->attr->time_to_die)
	{
		if (ft_check_alive(profile->status))
		{
			ft_lock(profile->status->public_mutex);
			profile->status->alive = DIE;
			ft_timestamp(profile->status->start_time, curr_time, DIE, id);
			return (1);
		}
	}
	return (0);
}
