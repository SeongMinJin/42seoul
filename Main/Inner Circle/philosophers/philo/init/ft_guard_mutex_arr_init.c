/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_guard_mutex_arr_init.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 22:07:35 by seojin            #+#    #+#             */
/*   Updated: 2022/09/21 22:15:20 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static pthread_mutex_t	ft_make_guard_mutex(void);

void	ft_guard_mutex_arr_init(t_status *status, int num)
{
	int				i;
	pthread_mutex_t	*guard_mutex_arr;

	guard_mutex_arr = (pthread_mutex_t *)malloc(num * sizeof(pthread_mutex_t));
	if (!guard_mutex_arr)
		status->guard_mutex_arr = NULL;
	else
	{
		i = 0;
		while (i < num)
			*(guard_mutex_arr + i++) = ft_make_guard_mutex();
		status->guard_mutex_arr = guard_mutex_arr;
	}
}

static pthread_mutex_t	ft_make_guard_mutex(void)
{
	pthread_mutex_t	mutex;

	pthread_mutex_init(&mutex, NULL);
	return (mutex);
}
