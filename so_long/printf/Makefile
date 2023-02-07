# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pperol <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/30 11:52:05 by pperol            #+#    #+#              #
#    Updated: 2022/06/09 10:56:02 by pperol           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c \
	ft_utils.c \
	ft_ptr2di.c\
	ft_u2pct.c

OBJ = $(SRC:.c=.o)

CC = clang

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

re: fclean all
