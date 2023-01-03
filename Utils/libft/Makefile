CC = cc

CFLAGS = -Wall -Wextra -Werror -c

NAME = libft.a

PT1 = ft_atoi.c \
		ft_isascii.c \
		ft_memcpy.c \
		ft_strlcat.c \
		ft_strrchr.c \
		ft_bzero.c \
		ft_isdigit.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_tolower.c \
		ft_calloc.c \
		ft_isprint.c \
		ft_memset.c \
		ft_strlen.c \
		ft_toupper.c \
		ft_isalnum.c \
		ft_memchr.c \
		ft_strchr.c \
		ft_strncmp.c \
		ft_isalpha.c \
		ft_memcmp.c \
		ft_strdup.c \
		ft_strnstr.c \

PT2 = ft_putchar_fd.c \
		ft_striteri.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_split.c \

GNL = get_next_line.c \
		get_next_line_utils.c \

BOUNUSPT = ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c \

CFILES = $(PT1) $(PT2) $(GNL)

AR = ar rcs

OBJECTS = $(CFILES:.c=.o)

BOUNUS_OBJ = $(BOUNUSPT:.c=.o)

all: $(NAME) bonus

$(NAME): $(OBJECTS) libft.h get_next_line.h
	$(AR) $@ $^

bonus : $(BOUNUS_OBJ) libft.h
	$(AR) $(NAME) $^

%.o : %.c libft.h get_next_line.h
	$(CC) $(CFLAGS) $< -o $@

clean :
	rm -rf $(OBJECTS) $(BOUNUS_OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: clean fclean all re bonus
