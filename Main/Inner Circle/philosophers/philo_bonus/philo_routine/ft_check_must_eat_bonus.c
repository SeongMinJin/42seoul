/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_must_eat_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:51:13 by seojin            #+#    #+#             */
/*   Updated: 2022/09/28 10:58:11 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

int	ft_check_must_eat(t_profile *profile)
{
	if (profile->eat_cnt == profile->status->must_eat_time)
		return (0);
	return (1);
}
