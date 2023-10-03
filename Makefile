NAME = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3 #-fsanitize=address
CHECKER = checker
SRC_FILES = main.c \
			ft_start_set.c \
			ft_split.c \
			ft_push_swap.c \
			ft_push_swap_utils.c \
			ft_op_b.c \
			ft_op_a.c \
			ft_error.c \
			ft_checks.c \
			ft_check_utils.c

INCLUDE = push_swap.h

OBJS = $(SRC_FILES:.c=.o)

all: lib $(NAME)

bonus:
	make -C checker_bonus
	cp checker_bonus/$(CHECKER) $(CHECKER)

%.o: %.c
	$(CC) -c $(CFLAGS)  $^

$(NAME): $(OBJS) $(INCLUDE)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)
	make -C checker_bonus clean

fclean: clean
	rm -f $(NAME)
	rm -f $(CHECKER)
	make -C checker_bonus fclean

re: fclean all

.PHONY: all clean fclean re lib