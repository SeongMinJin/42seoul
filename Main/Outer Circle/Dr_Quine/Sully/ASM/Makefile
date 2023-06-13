NAME = Sully
SOURCE = Sully.s
OBJECT = Sully.o

all : $(NAME)

$(NAME) : $(OBJECT)
	ld -lSystem $< -o $@

$(OBJECT) : 
	nasm -f macho64 $(SOURCE) -o $@

clean :
	rm -rf Sully_*
	rm -rf $(OBJECT)

fclean :
	make clean
	rm -rf $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re