# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: varodrig <varodrig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/30 12:55:57 by varodrig          #+#    #+#              #
#    Updated: 2024/10/30 13:57:41 by varodrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###########################################

## ARGUMENTS

NAME			= fractol
FLAGS			= -Wall -Wextra -Werror -g -I${MLX_DIR}
MLXFLAGS		= -L${MLX_DIR} -lmlx -lXext -lX11 -lm
CC				= cc

###########################################
## SOURCES

SRCS			= check_x_y.c draw.c events.c fractol.c init.c maths_func.c toolbox.c
OBJS			= ${SRCS:.c=.o}
HEADER			= fractol.h

##############################################################################
##MLX

MLX_DIR = ./mlx
MLX_GIT = https://github.com/42Paris/minilibx-linux.git
MLX = ${MLX_DIR}/libmlx.a

###########################################
## RULES

all: ${MLX} ${NAME}

${NAME}: ${OBJS} ${MLX}
		@${CC} ${OBJS} ${MLX} ${MLXFLAGS} -o ${NAME}
		@echo "Fractol compiled"

${MLX}:
	@if [ ! -d ${MLX_DIR} ]; then git clone ${MLX_GIT} ${MLX_DIR}; fi
	@${MAKE} -C ${MLX_DIR}

clean:
		@rm -f ${OBJS}
		@echo fractol CLEAN DONE

fclean:	clean
		@rm -f ${NAME}
		@echo fractol FCLEAN DONE

re: fclean all
		@echo fractol RE DONE

.PHONY: all clean fclean re