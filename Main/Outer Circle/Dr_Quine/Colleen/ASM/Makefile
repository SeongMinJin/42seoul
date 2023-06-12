NAME = Colleen
SOURCE = Colleen.s
OBJECT = Colleen.o

all : $(NAME)

$(NAME) : $(OBJECT)
	ld -lSystem $< -o $@

$(OBJECT) :
	nasm -f macho64 $(SOURCE) -o $@

clean :
	rm -rf $(OBJECT)

fclean :
	make clean
	rm -rf $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re