/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork_arr_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 10:34:07 by seojin            #+#    #+#             */
/*   Updated: 2022/09/21 20:19:37 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static pthread_mutex_t	ft_make_mutex(void);

void	ft_fork_arr_init(t_status *status, int num)
{
	int				i;
	pthread_mutex_t	*fork_arr;

	fork_arr = (pthread_mutex_t *)malloc(num * sizeof(pthread_mutex_t));
	if (!fork_arr)
		status->fork_arr = NULL;
	else
	{
		i = 0;
		while (i < num)
			*(fork_arr + i++) = ft_make_mutex();
		status->fork_arr = fork_arr;
	}
}

static pthread_mutex_t	ft_make_mutex(void)
{
	pthread_mutex_t	mutex;

	pthread_mutex_init(&mutex, NULL);
	return (mutex);
}
