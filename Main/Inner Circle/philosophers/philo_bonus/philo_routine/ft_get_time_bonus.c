/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_time_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 10:51:18 by seojin            #+#    #+#             */
/*   Updated: 2022/09/29 11:35:00 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

long	ft_get_time(void)
{
	struct timeval	time;
	long			curr_time;

	gettimeofday(&time, NULL);
	curr_time = time.tv_usec / 1000 + time.tv_sec * 1000;
	return (curr_time);
}

long	ft_transform_time(struct timeval time)
{
	long	transfromed_time;

	transfromed_time = time.tv_usec / 1000 + time.tv_sec * 1000;
	return (transfromed_time);
}
