# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 21:15:30 by seojin            #+#    #+#              #
#    Updated: 2022/09/29 11:59:00 by seojin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

cc = CC
CFLAGS = -Wall -Wextra -Werror

LIB = libphilo_bonus.a
MAIN_SRC = main_bonus.c
SRCS = main_bonus.c\
		ft_start_bonus.c\
		./init/ft_atoi_bonus.c\
		./init/ft_init_bonus.c\
		./init/ft_profile_init_bonus.c\
		./philo_routine/ft_check_alive_bonus.c\
		./philo_routine/ft_check_meal_bonus.c\
		./philo_routine/ft_check_must_eat_bonus.c\
		./philo_routine/ft_eat_bonus.c\
		./philo_routine/ft_get_time_bonus.c\
		./philo_routine/ft_monitoring_bonus.c\
		./philo_routine/ft_philo_routine_bonus.c\
		./philo_routine/ft_sleep_bonus.c\
		./philo_routine/ft_think_bonus.c\
		./philo_routine/ft_time_check_bonus.c\
		./philo_routine/ft_timestamp_bonus.c

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
