/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 12:37:44 by seojin            #+#    #+#             */
/*   Updated: 2022/10/03 11:14:10 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCT_H
# define PHILO_STRUCT_H

struct	s_attr;
struct	s_philo_profile;
struct	s_status;

typedef struct s_attr
{
	int	num_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	must_eat_time;
}	t_attr;

typedef struct s_philo_profile
{
	int				id;
	int				eat_cnt;
	t_attr			*attr;
	struct timeval	last_eat_time;
	struct s_status	*status;
	pthread_mutex_t	*fork1;
	pthread_mutex_t	*fork2;
	int				*fork1_usage;
	int				*fork2_usage;
}	t_philo_profile;

typedef struct s_status
{
	int				must_eat;
	int				alive;
	int				*fork_usage_arr;
	t_attr			*attr;
	t_philo_profile	*philo_arr;
	pthread_mutex_t	*public_mutex;
	pthread_mutex_t	*guard_mutex_arr;
	pthread_mutex_t	*fork_arr;
	struct timeval	start_time;
}	t_status;

#endif
