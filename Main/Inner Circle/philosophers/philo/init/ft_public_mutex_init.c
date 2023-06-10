/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_public_mutex_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 07:43:04 by seojin            #+#    #+#             */
/*   Updated: 2022/10/03 11:24:21 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_public_mutex_init(t_status *status)
{
	pthread_mutex_t	*public_mutex;

	public_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!public_mutex)
		status->public_mutex = NULL;
	else
	{
		pthread_mutex_init(public_mutex, NULL);
		status->public_mutex = public_mutex;
	}
}
