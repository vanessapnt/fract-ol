# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: varodrig <varodrig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/31 13:51:03 by varodrig          #+#    #+#              #
#    Updated: 2024/10/31 16:23:16 by varodrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      = cc
CFLAGS  = -Wall -Wextra -Werror -Og -Imlx
LDFLAGS = -L./mlx -lmlx -lXext -lX11 -lm
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

### MLX ###########################################################################

MLX_DIR = mlx
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_REPO = https://github.com/42Paris/minilibx-linux

### RULES #######################################################################

all: $(MLX_LIB) $(NAME)

$(MLX_LIB):
	@if [ ! -d $(MLX_DIR) ]; then \
		echo "Cloning minilibx repository..."; \
		git clone $(MLX_REPO) $(MLX_DIR); \
	fi
	@$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f $(MLX_LIB)
cleanmlx:
	rm -rf $(MLX_DIR)

re: fclean all

.PHONY: all re fclean clean

