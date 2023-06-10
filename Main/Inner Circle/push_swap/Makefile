# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 13:54:57 by seojin            #+#    #+#              #
#    Updated: 2022/08/31 20:38:40 by seojin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIB = libpush_swap.a

MAIN_SRC = main.c
CHECKER_MAIN_SRC = ./checker_src/checker.c
SRCS = main.c\
		./rules/ft_swap.c\
		./rules/ft_push.c\
		./rules/ft_rotate.c\
		./rules/ft_reverse_rotate.c\
		./init/ft_exit.c\
		./init/ft_free.c\
		./init/ft_init.c\
		./init/ft_lst_func.c\
		ft_asc_desc_check.c\
		ft_hard_sort.c\
		ft_hard_sort_util.c\
		ft_get_min_max.c\
		ft_push_swap.c\
		ft_get_pivot.c\
		ft_get_pivot_util.c\
		ft_quick_greedy_sort.c\
		ft_greedy_sort_util.c\
		ft_get_movement_cnt.c\
		ft_optimize.c\
		./checker_src/checker.c\
		./checker_src/ft_verify.c\
		./checker_src/ft_verify2.c\
		./checker_src/ft_checker_push.c\
		./checker_src/ft_checker_rotate.c\
		./checker_src/ft_checker_reverse_rotate.c\
		./checker_src/ft_checker_swap.c\
		./checker_src/checker_util.c\
		./checker_src/ft_split.c
OBJS = $(SRCS:%.c=%.o)

all : $(NAME)

bonus : $(NAME) $(BONUS)

$(NAME) : $(LIB)
	$(CC) $(CFLAGS) $^ $(MAIN_SRC) -o $@

$(BONUS) : $(LIB)
	$(CC) $(CFLAGS) $^ $(CHECKER_MAIN_SRC) -o $@
	
$(LIB) : $(OBJS)
	ar rc $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME) $(BONUS) $(LIB)

re : fclean all

.PHONY : all clean fclean re bonus
