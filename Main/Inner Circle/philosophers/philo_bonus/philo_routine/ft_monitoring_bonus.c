/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitoring_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:43:56 by seojin            #+#    #+#             */
/*   Updated: 2022/09/28 10:56:15 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	*ft_monitoring(void *arg)
{
	t_profile		*profile;
	struct timeval	curr_time;

	profile = (t_profile *)arg;
	while (1)
	{
		gettimeofday(&curr_time, NULL);
		ft_check_meal(profile, curr_time);
	}
	return (NULL);
}
