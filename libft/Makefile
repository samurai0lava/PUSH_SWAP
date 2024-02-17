NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar rc

SRCLIB = ./libft_man/ft_bzero.c \
    ./libft_man/ft_isalnum.c \
    ./libft_man/ft_isascii.c\
    ./libft_man/ft_isprint.c\
    ./libft_man/ft_memchr.c\
    ./libft_man/ft_memcpy.c\
    ./libft_man/ft_memset.c \
    ./libft_man/ft_strchr.c\
    ./libft_man/ft_striteri.c\
    ./libft_man/ft_strlcat.c\
    ./libft_man/ft_strlen.c\
    ./libft_man/ft_strncmp.c\
    ./libft_man/ft_strrchr.c\
    ./libft_man/ft_substr.c\
    ./libft_man/ft_toupper.c\
    ./libft_man/ft_atoi.c\
    ./libft_man/ft_calloc.c\
    ./libft_man/ft_isalpha.c\
    ./libft_man/ft_isdigit.c\
    ./libft_man/ft_itoa.c\
    ./libft_man/ft_memcmp.c\
    ./libft_man/ft_memmove.c\
    ./libft_man/ft_split.c\
    ./libft_man/ft_strdup.c\
    ./libft_man/ft_strjoin.c\
    ./libft_man/ft_strlcpy.c\
    ./libft_man/ft_strmapi.c\
    ./libft_man/ft_strnstr.c\
    ./libft_man/ft_strtrim.c\
    ./libft_man/ft_tolower.c\
    ./libft_man/ft_putchar_fd.c\
    ./libft_man/ft_putstr_fd.c\
    ./libft_man/ft_putendl_fd.c\
    ./libft_man/ft_putnbr_fd.c
    
SRCBONUSLIB = ./libft_bonus/ft_lstadd_back_bonus.c\
    ./libft_bonus/ft_lstadd_front_bonus.c\
    ./libft_bonus/ft_lstclear_bonus.c\
    ./libft_bonus/ft_lstdelone_bonus.c\
    ./libft_bonus/ft_lstlast_bonus.c\
    ./libft_bonus/ft_lstnew_bonus.c\
    ./libft_bonus/ft_lstsize_bonus.c\
    ./libft_bonus/ft_lstiter_bonus.c\

SRCPRINTF = ./ft_printf/ft_printf.c\
	./ft_printf/ft_printf.c
    
OBJ = $(SRC:.c=.o)

OBJBONUS = $(SRCBONUS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(AR) $(NAME) $(OBJ)

$(OBJ) : $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

$(OBJBONUS) : $(SRCBONUS)
	$(CC) $(CFLAGS) -c $(SRCBONUS)
	$(AR) $(NAME) $(OBJBONUS)

bonus : $(OBJBONUS)

clean :
	rm -f $(OBJ) $(OBJBONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean bonus re
