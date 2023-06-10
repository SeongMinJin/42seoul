# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seojin <seojin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/11 20:37:29 by seojin            #+#    #+#              #
#    Updated: 2022/08/12 11:05:15 by seojin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_MANDATORY = server client
NAME_BONUS = server_bonus client_bonus
LIBRARY = lib.a
LIBRARY_BONUS = lib_bonus.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SERVER_MAIN = ./server_srcs/server.c
SERVER_BONUS_MAIN = ./server_srcs/server_bonus.c
SERVER_SRC = ./server_srcs/ft_null_guard.c\
			./server_srcs/ft_print.c\
			./server_srcs/ft_putpid.c\
			./server_srcs/ft_ready_to_get_next_letter.c\
			./server_srcs/server_utility.c
SERVER_BONUS_SRC = ./server_srcs/ft_null_guard_bonus.c\
					./server_srcs/ft_print_bonus.c\
					./server_srcs/ft_putpid_bonus.c\
					./server_srcs/ft_ready_to_get_next_letter_bonus.c\
					./server_srcs/server_utility_bonus.c
SERVER_OBJECTS = $(SERVER_SRC:.c=.o)
SERVER_BONUS_OBJECTS = $(SERVER_BONUS_SRC:.c=.o)

CLIENT_MAIN = ./client_srcs/client.c
CLIENT_BONUS_MAIN = ./client_srcs/client_bonus.c
CLIENT_SRC = ./client_srcs/client_utility.c
CLIENT_BONUS_SRC = ./client_srcs/client_utility_bonus.c
CLIENT_OBJECTS = $(CLIENT_SRC:%.c=%.o)
CLIENT_BONUS_OBJECTS = $(CLIENT_BONUS_SRC:%.c=%.o)

ifdef BONUS
	NAME = $(NAME_MANDATORY) $(NAME_BONUS)
else
	NAME = $(NAME_MANDATORY)
endif

all : $(NAME)

bonus :
	make BONUS=1 all

server : $(LIBRARY)
	$(CC) $(CFLAGS) $? $(SERVER_MAIN) -o server
	
client : $(LIBRARY)
	$(CC) $(CFLAGS) $? $(CLIENT_MAIN) -o client

server_bonus : $(LIBRARY_BONUS)
	$(CC) $(CFLAGS) $? $(SERVER_BONUS_MAIN) -o $@

client_bonus : $(LIBRARY_BONUS)
	$(CC) $(CFLAGS) $? $(CLIENT_BONUS_MAIN) -o $@

$(LIBRARY) : $(SERVER_OBJECTS) $(CLIENT_OBJECTS)
	ar rc $@ $?
$(LIBRARY_BONUS) : $(SERVER_BONUS_OBJECTS) $(CLIENT_BONUS_OBJECTS)
	ar rc $@ $?

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean :
	rm -rf $(SERVER_OBJECTS) $(SERVER_BONUS_OBJECTS) $(CLIENT_OBJECTS) $(CLIENT_BONUS_OBJECTS)

fclean : clean
	rm -rf $(NAME_MANDATORY) $(NAME_BONUS) $(LIBRARY) $(LIBRARY_BONUS)

re : fclean all

.PHONY : all clean fclean re bonus
