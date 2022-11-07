# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gehebert <gehebert@42quebec.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/15 06:36:32 by gehebert          #+#    #+#              #
#    Updated: 2022/02/02 10:39:59 by gehebert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# _*_ Makefile _*_

NAME = libft.a
CFLAGS = -g -fsanitize=address -Wall -Wextra -Werror -I $(HEADER)

SRC = *.c 

OBJ = $(SRC:%.c=%.o)

CC = gcc

RM = rm -rf

HEADER = ./

all: $(NAME)

$(NAME): $(OBJ) 
	ar rcs $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

