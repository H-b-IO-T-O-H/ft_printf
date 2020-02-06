
.PHONY: all clean fclean re

NAME = libftprintf.a

CFLAG = -C -Wall -Wextra -Werror

SRC = srcs/ft_itoa.c \
    srcs/ft_printf.c \
    srcs/func.c \
    srcs/treat_f.c \
    srcs/treatment.c \
    srcs/write_func.c \
    srcs/check.c \


OBJ		= $(SRC:.c=.o)

INCLUDE = ft_printf.h

CC		= gcc

all: $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -o $@ -c $<

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ)
	rm -rf $(DIR_O)

fclean: clean
	rm -rf $(NAME)

re: fclean all
