INCLUDES = ../../include
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES)
NAME = libft.a
CC = cc

OBJS = ft_atoi.o ft_bzero.o ft_calloc.o ft_isalnum.o ft_isalpha.o ft_isascii.o \
		ft_isdigit.o ft_isprint.o ft_memchr.o ft_memcmp.o ft_memcpy.o ft_memmove.o \
		ft_memset.o ft_strchr.o ft_strdup.o ft_strlcat.o ft_strlcpy.o ft_strlen.o \
		ft_strncmp.o ft_strnstr.o ft_strrchr.o ft_tolower.o ft_toupper.o ft_substr.o \
		ft_strjoin.o ft_split.o ft_strtrim.o ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o \
		ft_itoa.o ft_strmapi.o ft_putnbr_fd.o ft_striteri.o ft_lstsize.o ft_lstlast.o ft_lstadd_back.o\
		ft_lstdelone.o ft_lstclear.o ft_lstiter.o ft_lstmap.o ft_lstnew.o ft_lstadd_front.o ft_lstinsert.o\
		ft_swap.o ft_min.o ft_max.o

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) cr $@ $^

clean:
	-$(RM) $(OBJS)

fclean: clean
	-$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re
