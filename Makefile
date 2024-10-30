CC      = cc
CFLAGS  = -Wall -Wextra -Werror -Og -Imlx
LDFLAGS = -Lmlx -lmlx -lXext -lX11 -lm
# -fsanitize=address -fsanitize=undefined -fno-omit-frame-pointer
NAME    = fractol

### SRC ########################################################################

SRCS    = fractol.c \
           init.c \
           check_x_y.c \
           draw.c \
           events.c \
           maths_func.c \
           toolbox.c

### OBJS ###########################################################################

OBJS    = $(SRCS:.c=.o)

### RULES #######################################################################

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re fclean clean
