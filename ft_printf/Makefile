NAME = 		libftprintf.a

SRCS = 	ft_printf.c \
		ft_printf_utils.c \
		ft_printf_utils2.c

HEADR = ft_printf.h

CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(HEADR)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:
	@make fclean
	@make all

.PHONY: all clean fclean re
