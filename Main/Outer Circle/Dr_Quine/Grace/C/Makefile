NAME = Grace
SOURCE = Grace.c

all :
	cc -Wall -Werror -Wextra $(SOURCE) -o $(NAME);

clean :
	rm -rf Grace_kid.c

fclean :
	clean
	rm -rf $(NAME)

re :
	fclean
	all

.PHONY : all clean fclean re