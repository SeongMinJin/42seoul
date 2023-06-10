/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:52:19 by seojin            #+#    #+#             */
/*   Updated: 2022/09/28 10:55:58 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

/* headers for allowed functions*/
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <signal.h>
# include <sys/wait.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/stat.h>

/* headers for struct & macro*/
# include "philo_struct_bonus.h"
# include "philo_macro_bonus.h"

/* functions for init */
int			ft_atoi(char *s);
t_status	*ft_init(char **av);

/* functions for parent process */
void		ft_start(t_status *status);
void		ft_clean(t_status *status);

/* functions for child process */
void		ft_philo_routine(t_status *status);
void		ft_timestamp(struct timeval start_time, \
			struct timeval curr_time, int flag, int id);
void		ft_check_meal(t_profile *profile, struct timeval curr_time);
void		*ft_monitoring(void *arg);
void		ft_eat(t_profile *profile);
void		ft_sleep(t_profile *profile);
void		ft_think(t_profile *profile);
long		ft_get_time(void);
long		ft_transform_time(struct timeval time);
int			ft_check_alive(t_profile *profile);
int			ft_check_must_eat(t_profile *profile);
int			ft_eat_time_check(t_profile *profile, long start_time);
int			ft_sleep_time_check(t_profile *profile, long start_time);
t_profile	*ft_profile_init(t_status *status);

#endif
