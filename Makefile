NAME = 		pipex

SRCS = 	pipex.c

HEADR = pipex.h

CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

all: $(NAME)

OBJ = $(OBJS)

$(NAME): $(OBJ) $(HEADR)
	@make -C ./mlx
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:
	@make fclean
	@make all

.PHONY: all clean fclean re bonus
