##
## EPITECH PROJECT, 2023
## MAKEFILE
## File description:
## Makefile
##

NAME 		= 	libasm.so

LDFLAGS		=	-shared -fPIC

SRC_DIR 	= 	./src/

TEST_DIR	=	./tests/

SRCS 		= 	$(SRC_DIR)strlen.asm 		\
				$(SRC_DIR)strchr.asm		\
				$(SRC_DIR)strrchr.asm		\
				$(SRC_DIR)memset.asm		\
				$(SRC_DIR)memcpy.asm		\
				$(SRC_DIR)strcmp.asm		\
				$(SRC_DIR)memmove.asm		\
				$(SRC_DIR)strncmp.asm		\
				$(SRC_DIR)strcasecmp.asm	\

OBJS 		= 	$(SRCS:.asm=.o)


%.o: %.asm
	nasm -f elf64 -o $@ $<

all: $(NAME)
	@echo "Build ok!"

$(NAME): $(OBJS)
	ld -o $(NAME) $(OBJS) $(LDFLAGS)

tests_run: fclean all
	make -C $(TEST_DIR)

clean:
	$(RM) $(OBJS)
	make clean -C $(TEST_DIR) -s
	@echo "Clean ok!"

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(TEST_DIR) -s
	@echo "Fclean ok!"

re: fclean all

.PHONY: all tests_run clean fclean re
