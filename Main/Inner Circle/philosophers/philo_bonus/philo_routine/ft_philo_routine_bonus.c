/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_routine_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:59:14 by seojin            #+#    #+#             */
/*   Updated: 2022/09/29 12:02:52 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	ft_philo_routine(t_status *status)
{
	t_profile	*profile;
	pthread_t	tid;

	profile = ft_profile_init(status);
	profile->last_eat_time = profile->status->start_time;
	pthread_create(&tid, NULL, ft_monitoring, profile);
	pthread_detach(tid);
	while (ft_check_must_eat(profile))
	{
		ft_eat(profile);
		ft_sleep(profile);
		ft_think(profile);
	}
	exit(0);
}
