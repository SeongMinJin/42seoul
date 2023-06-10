/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simulation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 17:35:42 by seojin            #+#    #+#             */
/*   Updated: 2022/09/29 11:27:40 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*ft_simulation(void *arg)
{
	t_philo_profile	*profile;
	int				must_eat;
	int				id;

	profile = (t_philo_profile *)arg;
	must_eat = profile->attr->must_eat_time;
	id = profile->id;
	if (id % 2 == 1)
		usleep(200);
	while (1)
	{
		if (profile->eat_cnt == must_eat)
		{
			ft_lock(profile->status->public_mutex);
			profile->status->alive = DIE;
			ft_unlock(profile->status->public_mutex);
			break ;
		}
		ft_eat(profile, id);
		ft_sleep(profile, id);
		ft_think(profile, id);
	}
	return (NULL);
}
