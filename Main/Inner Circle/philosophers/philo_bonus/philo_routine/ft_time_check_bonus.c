/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_check_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 10:50:41 by seojin            #+#    #+#             */
/*   Updated: 2022/09/27 11:57:39 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

int	ft_eat_time_check(t_profile *profile, long start_time)
{
	if (ft_get_time() - start_time >= profile->status->time_to_eat)
		return (0);
	else
		return (1);
}

int	ft_sleep_time_check(t_profile *profile, long start_time)
{
	if (ft_get_time() - start_time >= profile->status->time_to_sleep)
		return (0);
	else
		return (1);
}
