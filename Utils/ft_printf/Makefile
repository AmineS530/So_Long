CC = cc

CFLAGS = -Wall -Wextra -Werror -c

NAME = libftprintf.a

CFILES = ft_printf.c \
		ft_printf_utils_hex.c \
		ft_printf_utils.c \

OBJ = $(CFILES:.c=.o)

AR = ar rcs

all: $(NAME)

%.o : %.c ft_printf.h
	$(CC) $(CFLAGS) $< -o $@

$(NAME): $(OBJ) ft_printf.h
	$(AR)  $@ $^

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re
