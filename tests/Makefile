##
## EPITECH PROJECT, 2023
## MAKEFILE
## File description:
## Makefile
##

NAME		=	unit_tests

CPPFLAGS	=	-W -Wall -Wextra -Werror

LDFLAGS		=	-lcriterion

COVFLAGS	=	-lcriterion -lgcov

SRC_DIR		=	../src/

SRC_TESTS	=	$(SRC_DIR)strlen.asm 		\
				$(SRC_DIR)strchr.asm		\
				$(SRC_DIR)strrchr.asm		\
				$(SRC_DIR)memset.asm		\
				$(SRC_DIR)memcpy.asm		\
				$(SRC_DIR)strcmp.asm		\
				$(SRC_DIR)memmove.asm		\
				$(SRC_DIR)strncmp.asm		\
				$(SRC_DIR)strcasecmp.asm	\

UT_FILES	=	tests_strlen.c 				\
				tests_strchr.c				\
				tests_strrchr.c				\
				tests_memset.c				\
				tests_memcpy.c				\
				tests_strcmp.c				\
				tests_memmove.c				\
				tests_strncmp.c				\
				tests_strcasecmp.c			\

SRC_OBJS	=	$(SRC_TESTS:.c=.o)

UT_OBJS		=	$(UT_FILES:.c=.o)

%.o: %.asm
	nasm -f elf64 -o $@ $<

all: $(NAME)
	@echo "Build ok!"

$(NAME) : $(SRC_OBJS)
	ld -o $(NAME) $(OBJS) -shared -fPIC $(LDFLAGS)
	$(CC) -c $(UT_FILES) $(CPPFLAGS)
	$(CC) -o $(NAME) *.o $(CPPFLAGS) $(COVFLAGS)
	./$(NAME)

clean:
	$(RM) *.html
	$(RM) *.css
	$(RM) $(SRC_DIR)*.gcno
	$(RM) $(SRC_DIR)*.gcda
	$(RM) $(TEST_DIR)*.gcda
	$(RM) $(TEST_DIR)*.gcno
	$(RM) $(TEST_DIR)*.o
	$(RM) $(UT_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all build_lib clean fclean re
