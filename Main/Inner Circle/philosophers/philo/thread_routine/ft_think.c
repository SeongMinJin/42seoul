/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_think.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:00:30 by seojin            #+#    #+#             */
/*   Updated: 2022/09/29 11:28:38 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_think(t_philo_profile *profile, int id)
{
	struct timeval	curr_time;

	gettimeofday(&curr_time, NULL);
	ft_lock(profile->status->public_mutex);
	ft_timestamp(profile->status->start_time, curr_time, THINK, id);
	ft_unlock(profile->status->public_mutex);
}
