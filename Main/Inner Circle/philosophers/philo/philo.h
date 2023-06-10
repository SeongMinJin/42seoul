/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 17:45:42 by seojin            #+#    #+#             */
/*   Updated: 2022/10/03 11:20:33 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* headers for allowed functions*/
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

/* headers for struct & macro*/
# include "philo_struct.h"
# include "philo_macro.h"

/* functions for init */
int				ft_atoi(char *s);
int				*ft_get_fork_usage(int id, t_status *status);
void			ft_attr_init(t_status *status, char **av);
void			ft_fork_arr_init(t_status *status, int num);
void			ft_fork_usage_arr_init(t_status *status, int num);
void			ft_public_mutex_init(t_status *status);
void			ft_philo_profile_init(t_status *status, int num);
void			ft_guard_mutex_arr_init(t_status *status, int num);
pthread_mutex_t	*ft_get_fork(int id, t_status *status);
t_status		*ft_init(char **av);

/* functions for main thread */
void			ft_start(t_status *status);
void			ft_clean(t_status *status);
void			ft_monitoring(t_status *status, int num);
int				ft_check_meal(t_philo_profile *profile, \
				struct timeval curr_time, int id);

/* functions for thread routine */
void			*ft_simulation(void *arg);
void			ft_eat(t_philo_profile *profile, int id);
void			ft_sleep(t_philo_profile *profile, int id);
void			ft_think(t_philo_profile *profile, int id);
long			ft_transform_time(struct timeval time);
int				ft_eat_time_check(t_philo_profile *profile, long last_eat_time);
int				ft_sleep_time_check(t_philo_profile *profile, long start_time);

/* functions for common */
int				ft_check_alive(t_status *status);
long			ft_get_time(void);
void			ft_lock(pthread_mutex_t *mutex);
void			ft_unlock(pthread_mutex_t *mutex);
void			ft_timestamp(struct timeval start_time, \
				struct timeval curr_time, int flag, int id);

#endif
