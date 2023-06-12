NAME = Sully
SOURCE = Sully.c

all :
	cc -Wall -Werror -Wextra $(SOURCE) -o $(NAME);

clean :
	rm -rf Sully_*

fclean :
	clean
	rm -rf $(NAME)

re :
	fclean
	all

.PHONY : all clean fclean re