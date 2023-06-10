/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 17:43:15 by seojin            #+#    #+#             */
/*   Updated: 2022/10/03 11:24:27 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	ft_check_status(t_status *status);

t_status	*ft_init(char **av)
{
	t_status	*status;

	status = (t_status *)malloc(sizeof(t_status));
	if (!status)
		return (NULL);
	ft_attr_init(status, av);
	if (!status->attr)
		return (NULL);
	ft_fork_arr_init(status, status->attr->num_of_philo);
	ft_fork_usage_arr_init(status, status->attr->num_of_philo);
	ft_guard_mutex_arr_init(status, status->attr->num_of_philo);
	ft_public_mutex_init(status);
	ft_philo_profile_init(status, status->attr->num_of_philo);
	if (ft_check_status(status))
		return (NULL);
	status->must_eat = 0;
	status->alive = ALIVE;
	return (status);
}

static int	ft_check_status(t_status *status)
{
	if (!status->fork_arr)
		return (1);
	else if (!status->fork_usage_arr)
		return (1);
	else if (!status->guard_mutex_arr)
		return (1);
	else if (!status->public_mutex)
		return (1);
	else if (!status->philo_arr)
		return (1);
	else
		return (0);
}
