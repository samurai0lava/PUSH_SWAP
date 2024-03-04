NAME = push_swap
LIB = /libft/libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC = push_swap.c\
	stack_op.c\
	utils.c\
	check_errors.c\
	parsing.c\
	parsing2.c\
	main.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
    $(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)

%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    rm -f $(OBJ)

fclean: clean
    rm -f $(NAME)

re: fclean all




