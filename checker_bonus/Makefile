NAME = checker
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3
GNL = gnl.a
SRC_FILES =	main.c \
			ft_split.c \
			ft_push_swap.c \
			ft_op_b.c \
			ft_op_a.c \
			ft_error.c \
			ft_move.c

INCLUDE = checker.h

OBJS = $(SRC_FILES:.c=.o)

all: lib $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS)  $^

lib:
	make -C gnl
	cp gnl/$(GNL) $(GNL)

$(NAME): $(OBJS) $(INCLUDE)
	$(CC) $(CFLAGS) $(OBJS) $(GNL) -o $(NAME)

clean:
	rm -f $(OBJS)
	make -C gnl clean

fclean: clean
	rm -f $(NAME)
	rm -f $(GNL)
	make -C gnl fclean

re: fclean all

.PHONY: all clean fclean re lib