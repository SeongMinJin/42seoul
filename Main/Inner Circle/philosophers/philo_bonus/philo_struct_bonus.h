/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:53:05 by seojin            #+#    #+#             */
/*   Updated: 2022/09/27 19:42:16 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCT_BONUS_H
# define PHILO_STRUCT_BONUS_H

struct	s_status;

typedef struct s_profile
{
	int				alive;
	int				eat_cnt;
	struct timeval	last_eat_time;
	struct s_status	*status;
	sem_t			*private_sem;
}	t_profile;

typedef struct s_status
{
	int				id;
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_time;
	struct timeval	start_time;
	sem_t			*sem;
	sem_t			*public_sem;
}	t_status;

#endif
