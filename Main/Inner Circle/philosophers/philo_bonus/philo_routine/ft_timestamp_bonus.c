/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_timestamp_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 20:54:56 by seojin            #+#    #+#             */
/*   Updated: 2022/09/29 11:58:08 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	ft_timestamp(struct timeval start_time, \
struct timeval curr_time, int flag, int id)
{
	long	time;
	long	sec;
	int		usec;

	sec = (curr_time.tv_sec - start_time.tv_sec) * 1000000;
	usec = (curr_time.tv_usec - start_time.tv_usec);
	time = (sec + usec) / 1000 + 1;
	if (flag == LIFT_FORK)
		printf("%ld %d has taken a fork\n", time, id);
	else if (flag == EAT)
		printf("%ld %d is eating\n", time, id);
	else if (flag == THINK)
		printf("%ld %d is thinking\n", time, id);
	else if (flag == SLEEP)
		printf("%ld %d is sleeping\n", time, id);
	else
		printf("%ld %d died\n", time, id);
}
