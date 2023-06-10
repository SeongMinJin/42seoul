/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_think_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:00:30 by seojin            #+#    #+#             */
/*   Updated: 2022/09/29 11:36:23 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	ft_think(t_profile *profile)
{
	struct timeval	curr_time;

	sem_wait(profile->status->public_sem);
	gettimeofday(&curr_time, NULL);
	ft_timestamp(profile->status->start_time, curr_time, \
	THINK, profile->status->id);
	sem_post(profile->status->public_sem);
}
