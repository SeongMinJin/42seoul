/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_alive_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:40:37 by seojin            #+#    #+#             */
/*   Updated: 2022/09/27 22:37:29 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

int	ft_check_alive(t_profile *profile)
{
	sem_wait(profile->private_sem);
	if (profile->alive == DIE)
	{
		sem_post(profile->private_sem);
		return (0);
	}
	sem_post(profile->private_sem);
	return (1);
}
