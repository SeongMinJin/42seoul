/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitoring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:24:24 by seojin            #+#    #+#             */
/*   Updated: 2022/09/28 23:47:54 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_monitoring(t_status *status, int num)
{
	struct timeval	curr_time;
	int				i;

	while (ft_check_alive(status))
	{
		i = 0;
		while (i < num && ft_check_alive(status))
		{
			gettimeofday(&curr_time, NULL);
			if (ft_check_meal(&status->philo_arr[i], curr_time, i))
				return ;
			i++;
		}
	}
}
