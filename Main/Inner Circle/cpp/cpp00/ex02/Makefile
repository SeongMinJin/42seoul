# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/05 14:26:13 by seojin            #+#    #+#              #
#    Updated: 2022/11/05 14:32:01 by seojin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = account

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

LIB = libaccount.a

SRCS = Account.cpp tests.cpp
OBJS = $(SRCS:%.cpp=%.o)

all : $(NAME)

$(NAME) : $(LIB)
	$(CC) $(LIB) tests.cpp -o $@

$(LIB) : $(OBJS)
	ar rc $@ $^

%.o : %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(LIB) $(NAME)

re : fclean all

.PHONY : all clean fclean re
