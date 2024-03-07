NAME = push_swap
LIB = libft/libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -g

SRC = stack_init.c\
    utils.c\
    parsing.c\
    parsing2.c\
    main.c\
	stack_op.c\
	sort_5.c\
	sort_3.c\
	push_swap.c
	
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
	@echo "$(YELLOW)..MAKING libft....................."
	@echo "Compiling PUSH_SWAP................$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $@
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