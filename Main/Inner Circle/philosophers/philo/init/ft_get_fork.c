/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_fork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:13:28 by seojin            #+#    #+#             */
/*   Updated: 2022/10/03 11:16:54 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

pthread_mutex_t	*ft_get_fork(int id, t_status *status)
{
	int				num;
	pthread_mutex_t	*fork_arr;

	num = status->attr->num_of_philo;
	fork_arr = status->fork_arr;
	if (id == num - 1)
		return (&fork_arr[0]);
	else
		return (&fork_arr[id + 1]);
}

int	*ft_get_fork_usage(int id, t_status *status)
{
	int	num;

	num = status->attr->num_of_philo;
	if (id == num - 1)
		return (&status->fork_usage_arr[0]);
	else
		return (&status->fork_usage_arr[id + 1]);
}
