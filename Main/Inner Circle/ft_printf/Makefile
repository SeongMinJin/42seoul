# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seojin <seojin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/27 12:17:51 by seojin            #+#    #+#              #
#    Updated: 2022/07/27 12:18:46 by seojin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c\
ft_check_specifier.c\
ft_putchar.c\
ft_putstr.c\
ft_putnbr.c\
ft_putmem.c

OBJECTS = $(SRCS:%.c=%.o)

RM = rm -f
INC = ./

all : $(NAME)

$(NAME) : $(OBJECTS)
	ar rc $@ $(OBJECTS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC)

clean :
	$(RM) $(OBJECTS) $(BONUS_OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
