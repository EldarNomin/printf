NAME = libftprintf.a

FLAG = -Wall -Wextra -Werror

SRC = ft_printf.c \
		ft_printf_utils.c \
		ft_spec_csd.c \
		ft_spec_pxu.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c 
	gcc $(FLAG) -c $^ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re