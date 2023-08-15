NAME = ft_ping

CC = gcc
CFLAGS = -Wall -Werror -Wextra -MMD

LIB = ft_ping.a
MAIN_SRC = main.c
SRCS = other.c 
OBJS_DIR = objs
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:%.c=%.o))
DEPS = $(OBJS:.o=.d) $(NAME:=.d)

all : $(NAME)

$(NAME) : $(LIB) $(MAIN_SRC)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJS_DIR) : 
	mkdir -p $@

$(LIB) : $(OBJS_DIR) $(OBJS)
	ar -rc $@ $(OBJS)

$(OBJS_DIR)/%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean :
	rm -rf $(OBJS_DIR) $(DEPS)

fclean : clean
	rm -rf $(LIB) $(NAME)

re :
	make fclean
	make all


.PHONY: all clean fclean re

-include $(DEPS)
