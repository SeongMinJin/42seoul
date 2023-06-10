# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 17:07:07 by seojin            #+#    #+#              #
#    Updated: 2022/11/05 14:39:05 by seojin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = Contact.cpp\
		PhoneBook.cpp\
		main.cpp

LIB = libphonebook.a
OBJS = $(SRCS:%.cpp=%.o)

all : $(NAME)

$(NAME) : $(LIB)
	$(CC) $(LIB) main.cpp -o $@

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
