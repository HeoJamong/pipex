NAME = 		pipex

SRCS = 	pipex.c \
		ft_memcpy.c \
		ft_split.c \
		ft_strjoin.c \
		path.c

HEADR = pipex.h

CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

all: $(NAME)

OBJ = $(OBJS)

$(NAME): $(OBJ) $(HEADR)
	@make re -C ./ft_printf
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) ./ft_printf/libftprintf.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:
	@make fclean
	@make allz

.PHONY: all clean fclean re
