TARGET = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJECTS = $(SRCS:%.c=%.o)
RM = rm -f
INCLUDE = includes/ft.h
all : $(TARGET)

$(TARGET) : $(OBJECTS)
	ar rc $@ $(OBJECTS)

$(OBJECTS) : $(SRCS)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE)

clean :
	$(RM) $(OBJECTS)

fclean : clean
	$(RM) $(TARGET)

re : fclean all

.PHONY : all clean fclean re
