NAME = Grace
SOURCE = Grace.c

all : $(NAME)

$(NAME) :
	cc -Wall -Werror -Wextra $(SOURCE) -o $(NAME);

clean :
	rm -rf Grace_kid.c

fclean :
	make clean
	rm -rf $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re