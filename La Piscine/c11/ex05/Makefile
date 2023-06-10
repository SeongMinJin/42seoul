NAME = do-op
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = srcs/do-op.c srcs/ft_add.c srcs/ft_sub.c srcs/ft_div.c srcs/ft_multiply.c srcs/ft_module.c srcs/ft_putstr.c srcs/ft_putnbr.c srcs/ft_atoi.c
OBJETCS = $(SRCS:%.c=$.o)
RM = rm -f

all : $(NAME)

$(NAME) : $(SRCS)
	$(CC) $(CFLAGS) $^ -o $@

clean :
	$(RM) $(OBJECTS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
