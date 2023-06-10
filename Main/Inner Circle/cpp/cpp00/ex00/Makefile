# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 15:07:16 by seojin            #+#    #+#              #
#    Updated: 2022/11/05 14:39:02 by seojin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98


all : $(NAME)

NAME :
	$(CC) $(CFLAGS) megaphone.cpp -o $@

clean :
	rm -rf $(NAME)

fclean :
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
