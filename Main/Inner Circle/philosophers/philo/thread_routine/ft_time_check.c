/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 10:50:41 by seojin            #+#    #+#             */
/*   Updated: 2022/09/28 23:28:32 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_eat_time_check(t_philo_profile *profile, long last_eat_time)
{
	if (ft_get_time() - last_eat_time >= profile->attr->time_to_eat)
		return (0);
	else
		return (1);
}

int	ft_sleep_time_check(t_philo_profile *profile, long start_time)
{
	if (ft_get_time() - start_time >= profile->attr->time_to_sleep)
		return (0);
	else
		return (1);
}
