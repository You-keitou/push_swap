INCLUDES = include
NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES)

SRCS = $(wildcard src/*.c src/command_utils/*.c)
OBJS = ${SRCS:.c=.o}

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
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