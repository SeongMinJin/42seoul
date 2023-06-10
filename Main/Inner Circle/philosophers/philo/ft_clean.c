/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:52:06 by seojin            #+#    #+#             */
/*   Updated: 2022/10/03 11:20:49 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_clean(t_status *status)
{
	int	i;

	i = 0;
	while (i < status->attr->num_of_philo)
	{
		pthread_mutex_destroy(&(status->fork_arr[i]));
		i++;
	}
	pthread_mutex_destroy(status->public_mutex);
	free(status->attr);
	free(status->fork_arr);
	free(status->fork_usage_arr);
	free(status->guard_mutex_arr);
	free(status->philo_arr);
	free(status->public_mutex);
	free(status);
}
