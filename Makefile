NAME = 		pipex

SRCS = 	pipex.c \
		ft_memcpy.c \
		ft_split.c \
		ft_strjoin.c \
		path.c

HEADR = pipex.h

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

OBJS = $(SRCS:.c=.o)

all: $(NAME)

OBJ = $(OBJS)

$(NAME): $(OBJ) $(HEADR)
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
