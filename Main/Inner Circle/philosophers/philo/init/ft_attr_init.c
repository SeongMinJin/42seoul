/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attr_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 21:08:58 by seojin            #+#    #+#             */
/*   Updated: 2022/10/01 17:50:08 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	ft_attr_check(t_attr *attr);

void	ft_attr_init(t_status *status, char **av)
{
	t_attr	*attr;

	attr = (t_attr *)malloc(sizeof(t_attr));
	if (!attr)
		status->attr = NULL;
	else
	{
		attr->num_of_philo = ft_atoi(*av++);
		attr->time_to_die = ft_atoi(*av++);
		attr->time_to_eat = ft_atoi(*av++);
		attr->time_to_sleep = ft_atoi(*av++);
		if (*av)
			attr->must_eat_time = ft_atoi(*av);
		else
			attr->must_eat_time = NOT_EXIST;
		if (ft_attr_check(attr))
		{
			free(attr);
			status->attr = NULL;
		}
		else
			status->attr = attr;
	}
}

static int	ft_attr_check(t_attr *attr)
{
	if (attr->num_of_philo == ARG_ERR || attr->num_of_philo == 0)
		return (1);
	else if (attr->time_to_die == ARG_ERR)
		return (1);
	else if (attr->time_to_eat == ARG_ERR)
		return (1);
	else if (attr->time_to_sleep == ARG_ERR)
		return (1);
	else if (attr->must_eat_time == ARG_ERR)
		return (1);
	else
		return (0);
}
