# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pperol <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/08 11:37:55 by pperol            #+#    #+#              #
#    Updated: 2022/06/16 14:13:01 by pperol           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = main.c load_graphics.c load_game.c so_long_utils.c errors.c

CC = clang

CFLAGS = -Wall -Werror -Wextra -g3 #-fsanitize=address

OBJ = $(SRC:.c=.o)

MLX = minilibx

MLXA = minilibx/libmlx_Linux.a -lXext -lX11 -I minilibx/ 

LIBFT = libft

LIBFTA = libft/libft.a

PRINTF = printf

PRINTFA = printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(MLX)
	make -C $(LIBFT)
	make -C $(PRINTF)
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME) $(MLXA) $(LIBFTA) $(PRINTFA)
clean:
	make clean -C $(MLX)
	make clean -C $(LIBFT)
	make clean -C $(PRINTF)
	/bin/rm -f *.o

fclean: clean
	make fclean -C $(LIBFT)
	make fclean -C $(PRINTF)
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
