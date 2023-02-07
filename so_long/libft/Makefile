# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmarecha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/26 10:24:04 by lmarecha          #+#    #+#              #
#    Updated: 2021/12/06 17:19:59 by lmarecha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#INCLUDES = libft.h

NAME = libft.a

SRC = ft_isdigit.c ft_memcpy.c ft_strncmp.c \
	  ft_toupper.c ft_isalnum.c ft_isprint.c ft_memmove.c ft_strlcat.c \
	  ft_strnstr.c ft_atoi.c ft_isalpha.c ft_memchr.c ft_memset.c ft_strlcpy.c \
	  ft_strrchr.c ft_bzero.c ft_isascii.c ft_memcmp.c ft_strchr.c ft_strlen.c \
	  ft_tolower.c ft_strdup.c ft_calloc.c ft_substr.c ft_strjoin.c ft_strtrim.c \
	  ft_itoa.c ft_split.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
	  ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BNS = $(SRC) ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	  ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

BNSOBJ = $(BNS:.c=.o)

CC = clang

CFLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

bonus: $(BNSOBJ)
	ar rc $(NAME) $(BNSOBJ)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)
	
.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

re: fclean all
