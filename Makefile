INCLUDES = include
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES)

TEST_SRC = $(wildcard test/*.c)
TEST_OBJ = $(TEST_SRC:.c=.o)
TEST_NAME = TEST

RM = rm -f

tester: $(TEST_NAME)

$(TEST_NAME): $(TEST_OBJ)
	@${MAKE} -C printf
	$(CC) $(CFLAGS) -g -o $@ $^ printf/libftprintf.a

clean:
	@${MAKE} -C printf clean
	-$(RM) $(TEST_OBJ)

fclean: clean
	@${MAKE} -C printf fclean
	-$(RM) $(TEST_NAME)

re: fclean all

.PHONY: clean fclean re