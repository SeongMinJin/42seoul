/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_profile_init.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 10:23:33 by seojin            #+#    #+#             */
/*   Updated: 2022/10/03 11:15:37 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static t_philo_profile	ft_create_profile(t_status *status, int id);

void	ft_philo_profile_init(t_status *status, int num)
{
	int				i;
	t_philo_profile	*philo_arr;

	philo_arr = (t_philo_profile *)malloc(num * sizeof(t_philo_profile));
	if (!philo_arr)
		status->philo_arr = NULL;
	else
	{
		i = 0;
		while (i < num)
		{
			*(philo_arr + i) = ft_create_profile(status, i);
			i++;
		}
		status->philo_arr = philo_arr;
	}
}

static t_philo_profile	ft_create_profile(t_status *status, int id)
{
	t_philo_profile	profile;

	profile.id = id;
	profile.eat_cnt = 0;
	profile.fork1 = &status->fork_arr[id];
	profile.fork2 = ft_get_fork(id, status);
	profile.fork1_usage = &status->fork_usage_arr[id];
	profile.fork2_usage = ft_get_fork_usage(id, status);
	profile.attr = status->attr;
	profile.status = status;
	return (profile);
}
