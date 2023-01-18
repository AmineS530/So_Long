
NAME = so_long

SRC = game.c \
		mandatory/map_reader.c \
		map_checker.c \
		mandatory/map_renderer.c \
		mandatory/movements.c \

SRC_BONUS = game.c \
		bonus/map_reader_bonus.c \
		map_checker.c \
		bonus/map_renderer_bonus.c \
		bonus/movements_bonus.c \

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

LIBFT = Utils/libft/

ERRORS = Errors/errors_1.c \
			Errors/errors_2.c \
			Errors/errors_3.c \

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
	$(CC) $(OBJ) $(ERRORS_OBJ) -lmlx $(LIBFT_PATH) $(FT_PRINTF_PATH) -framework OpenGL -framework AppKit -o $(NAME)

bonus: $(OBJ_BONUS) $(ERRORS_OBJ) $(FT_PRINTF_PATH) $(LIBFT_PATH)
	$(CC) $(OBJ_BONUS) $(ERRORS_OBJ) -lmlx $(LIBFT_PATH) $(FT_PRINTF_PATH) -framework OpenGL -framework AppKit -o $(NAME)_bonus

clean :
	make -C $(LIBFT) clean
	make -C $(FT_PRINTF) clean
	rm -rf $(OBJ) $(ERRORS_OBJ) $(OBJ_BONUS)

fclean : clean
	make -C $(LIBFT) fclean
	make -C $(FT_PRINTF) fclean
	rm -rf $(NAME) $(NAME)_bonus

re : fclean all

.PHONY : all clean fclean re
