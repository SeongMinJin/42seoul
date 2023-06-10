# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    template.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/05 16:30:32 by seojin            #+#    #+#              #
#    Updated: 2022/12/07 18:00:37 by seojin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef NAME
	NAME = a.out
endif

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

ifndef SRCS
	SRCS = main.c
endif

LIB = lib.a
OBJS = $(SRCS:%.cpp=%.o)
OBJS_DIR = objs/

all : $(NAME)

$(NAME) : $(OBJS_DIR) $(LIB)
	$(CC) $(LIB) main.cpp -o $@

$(LIB) : $(addprefix $(OBJS_DIR), $(OBJS))
	ar rc $@ $^

$(OBJS_DIR) : 
	mkdir $@

$(OBJS_DIR)%.o : %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

clean :
	rm -rf $(addprefix $(OBJS_DIR), $(OBJS))

fclean : clean
	$(RM) $(LIB) $(NAME)
	$(RM) -r $(OBJS_DIR)

re : fclean all

.PHONY : all clean fclean re
