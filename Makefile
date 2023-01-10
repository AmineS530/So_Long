
NAME = so_long

SRC = map_reader.c \
		map_checker.c \
		map_renderer.c \


OBJ = $(SRC:.c=.o)

LIBFT = Utils/libft/

ERRORS = Errors/errors_1.c \
			Errors/errors_2.c \


ERRORS_OBJ = $(ERRORS:.c=.o)

LIBFT_PATH = Utils/libft/libft.a

FT_PRINTF = Utils/ft_printf/

FT_PRINTF_PATH = Utils/ft_printf/libftprintf.a

all : $(NAME) $(FT_PRINTF_PATH) $(LIBFT_PATH)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(LIBFT_PATH) :
	make -C $(LIBFT)

$(FT_PRINTF_PATH) :
	make -C $(FT_PRINTF)

$(NAME): $(OBJ) $(ERRORS_OBJ) $(FT_PRINTF_PATH) $(LIBFT_PATH)
	$(CC) $(OBJ) $(ERRORS_OBJ) -LTextures -lmlx $(LIBFT_PATH) $(FT_PRINTF_PATH) -framework OpenGL -framework AppKit -o $(NAME)

clean :
	make -C $(LIBFT) clean
	make -C $(FT_PRINTF) clean
	rm -rf $(OBJ) $(ERRORS_OBJ)

fclean : clean
	make -C $(LIBFT) fclean
	make -C $(FT_PRINTF) fclean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
