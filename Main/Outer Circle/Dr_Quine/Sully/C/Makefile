NAME = Sully
SOURCE = Sully.c

all : $(NAME)

$(NAME) :
	cc -Wall -Werror -Wextra $(SOURCE) -o $(NAME)

clean :
	rm -rf Sully_*

fclean :
	make clean
	rm -rf $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re
