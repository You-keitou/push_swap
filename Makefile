INCLUDES = include
NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES)

SRCS = $(wildcard src/*.c)
OBJS = ${SRCS:.c=.o}

TEST_SRC = $(wildcard test/*.c)
TEST_OBJ = $(TEST_SRC:.c=.o)
TEST_NAME = TEST

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	@${MAKE} -C printf
	$(CC) $(CFLAGS) -g -o $@ $^ printf/libftprintf.a

tester: $(TEST_NAME)

$(TEST_NAME): $(TEST_OBJ)
	@${MAKE} -C printf
	$(CC) $(CFLAGS) -g -o $@ $^ printf/libftprintf.a

clean:
	@${MAKE} -C printf clean
	-$(RM) $(TEST_OBJ)
	-$(RM) $(OBJS)

fclean: clean
	@${MAKE} -C printf fclean
	-$(RM) $(TEST_NAME)
	-$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re