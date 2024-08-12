# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/06 05:41:14 by logkoege          #+#    #+#              #
#    Updated: 2024/08/08 16:22:38 by logkoege         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
MLX = -L./minilibx-linux -lmlx -lX11 -lXext -lm
INCLUDES = -I./minilibx-linux -I.

SRC = so_long.c					\
		get_next_line.c			\
		get_next_line_utils.c	\
		so_long_utils.c
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

