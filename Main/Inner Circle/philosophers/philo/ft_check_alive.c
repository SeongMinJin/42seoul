/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_alive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:31:33 by seojin            #+#    #+#             */
/*   Updated: 2022/09/29 00:14:08 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_alive(t_status *status)
{
	ft_lock(status->public_mutex);
	if (status->alive == DIE)
	{
		ft_unlock(status->public_mutex);
		return (0);
	}
	ft_unlock(status->public_mutex);
	return (1);
}
