NAME = push_swap
LIB = libft/libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra 

SRC = parsing/stack_init.c\
    utils/utils.c\
    parsing/parsing.c\
    parsing/parsing2.c\
	parsing/utils_pars.c\
    utils/main.c\
	utils/stack_op.c\
	sorting/sort_5.c\
	sorting/sort_3.c\
	sorting/utils_sort_a.c\
	sorting/utils_sort_b.c\
	sorting/push_swap.c\
	sorting/moves.c\
	utils/ft_atoiv2.c\
	sorting/utils_sorting.c\
	
OBJ = $(SRC:.c=.o)

# ANSI color codes
YELLOW = \033[0;33m
GREEN = \033[0;32m
RESET = \033[0m
RED = \033[0;31m

all: $(LIB) $(NAME)

$(LIB):
	@$(MAKE) -C libft

$(NAME): $(OBJ)
	@echo "$(YELLOW)Compiling PUSH_SWAP................$(RESET)"
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $@
	@echo "$(GREEN)DONE............................$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Deleting objects..................."
	@echo "Cleaning......................$(RESET)"
	@$(MAKE) -C libft clean
	@rm -f $(OBJ)

fclean: clean
	@$(MAKE) -C libft fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re