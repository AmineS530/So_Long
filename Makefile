
NAME = so_long

SRC = game.c

OBJ = game.o

LIBFT = Utils/libft/

LIBFT_PATH = Utils/libft/libft.a

FT_PRINTF = Utils/ft_printf/

FT_PRINTF_PATH = Utils/ft_printf/libftprintf.a

all : $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
	$(CC) $(OBJ) -LTextures -lmlx $(LIBFT_PATH) $(FT_PRINTF_PATH) -framework OpenGL -framework AppKit -o $(NAME)

$(LIBFT) :
	make -C $(LIBFT)

$(FT_PRINTF) :
	make -C $(FT_PRINTF)

clean :
	make -C $(LIBFT) clean
	make -C $(FT_PRINTF) clean
	rm -rf $(OBJ)

fclean : clean

re : fclean all

.PHONY : all clean fclean re
