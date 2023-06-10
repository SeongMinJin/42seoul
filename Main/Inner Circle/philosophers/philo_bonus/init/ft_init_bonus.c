/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 21:08:58 by seojin            #+#    #+#             */
/*   Updated: 2022/10/01 17:48:19 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

static int	ft_status_check(t_status *status);
static void	ft_semaphore_init(t_status *status);

t_status	*ft_init(char **av)
{
	t_status	*status;

	status = (t_status *)malloc(sizeof(t_status));
	if (!status)
		exit (0);
	else
	{
		status->id = 0;
		status->num_of_philo = ft_atoi(*av++);
		status->time_to_die = ft_atoi(*av++);
		status->time_to_eat = ft_atoi(*av++);
		status->time_to_sleep = ft_atoi(*av++);
		if (*av)
			status->must_eat_time = ft_atoi(*av);
		else
			status->must_eat_time = NOT_EXIST;
		ft_semaphore_init(status);
		ft_status_check(status);
		return (status);
	}
}

static void	ft_semaphore_init(t_status *status)
{
	sem_unlink("sem");
	status->sem = sem_open("sem", O_CREAT | O_EXCL, \
	S_IRWXU | S_IRWXG | S_IRWXO, status->num_of_philo);
	sem_unlink("sem");
	sem_unlink("public_sem");
	status->public_sem = sem_open("public_sem", O_CREAT | O_EXCL, \
	S_IRWXU | S_IRWXG | S_IRWXO, 1);
	sem_unlink("public_sem");
}

static int	ft_status_check(t_status *status)
{
	if (status->num_of_philo == ARG_ERR)
		exit(1);
	else if (status->time_to_die == ARG_ERR)
		exit(1);
	else if (status->time_to_eat == ARG_ERR)
		exit(1);
	else if (status->time_to_sleep == ARG_ERR)
		exit(1);
	else if (status->must_eat_time == ARG_ERR)
		exit(1);
	else if (status->sem == SEM_FAILED)
		exit(1);
	else if (status->public_sem == SEM_FAILED)
		exit(1);
	else
		return (0);
}
