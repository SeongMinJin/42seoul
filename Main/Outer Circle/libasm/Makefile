NAME = libasm.a
MAIN = main

SRCS = ft_read.s\
			ft_strcmp.s\
			ft_strcpy.s\
			ft_strdup.s\
			ft_strlen.s\
			ft_write.s


OBJS = $(SRCS:%.s=%.o)

all : $(NAME)

main : $(NAME)
	cc -Wall -Werror -Wextra main.c $< -o $@

$(NAME) : $(OBJS)
	ar rc $@ $(OBJS)

%.o : %.s
	nasm -f macho64 $< -o $@

clean :
	$(RM) $(OBJS)

fclean :
	make clean
	$(RM) $(NAME)
	$(RM) $(MAIN)

re :
	make fclean
	make all

.PHONY : all clean flcean re main
