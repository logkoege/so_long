# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/06 05:41:14 by logkoege          #+#    #+#              #
#    Updated: 2024/10/04 23:49:36 by logkoege         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX = -L./minilibx-linux -lmlx -lX11 -lXext -lm
INCLUDES = -I./minilibx-linux -I.

SRC = so_long.c					\
		get_next_line.c			\
		get_next_line_utils.c	\
		so_long_utils.c			\
		img_fonctions.c			\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

