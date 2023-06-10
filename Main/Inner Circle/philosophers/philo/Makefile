# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/03 17:49:03 by seojin            #+#    #+#              #
#    Updated: 2023/02/27 14:41:20 by seojin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CFLAGS = -Wall -Werror -Wextra

LIB = libphilo.a
MAIN_SRC = main.c
SRCS =	main.c\
		ft_start.c\
		ft_timestamp.c\
		ft_monitoring.c\
		ft_clean.c\
		ft_check_alive.c\
		ft_check_meal.c\
		pthread_mutex_lock.c\
		pthread_mutex_unlock.c\
		./init/ft_atoi.c\
		./init/ft_init.c\
		./init/ft_attr_init.c\
		./init/ft_fork_arr_init.c\
		./init/ft_philo_profile_init.c\
		./init/ft_public_mutex_init.c\
		./init/ft_get_fork.c\
		./init/ft_guard_mutex_arr_init.c\
		./init/ft_fork_usage_arr_init.c\
		./thread_routine/ft_simulation.c\
		./thread_routine/ft_eat.c\
		./thread_routine/ft_sleep.c\
		./thread_routine/ft_think.c\
		./thread_routine/ft_get_time.c\
		./thread_routine/ft_time_check.c

OBJS = $(SRCS:%.c=%.o)

all : $(NAME)

$(NAME) : $(LIB)
	$(CC) $(CFLAGS) $(LIB) $(MAIN_SRC) -o $@

$(LIB) : $(OBJS)
	ar rc $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean :
	rm -f $(OBJS)

fclean : 
	make clean
	rm -f $(NAME) $(LIB)

re : 
	make fclean
	make all

.PHONY : all clean fclean re
