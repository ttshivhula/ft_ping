# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/11 11:29:48 by ttshivhu          #+#    #+#              #
#    Updated: 2018/10/09 11:21:41 by ttshivhu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_nm
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I.
SRC = main.c utils.c exit.c \

OBJ = $(SRC:.c=.o)
all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(OBJ)$(CFLAGS) -o $(NAME)
	@printf "\x1b[32mCompiled $(NAME)\x1b[0m\n"

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
