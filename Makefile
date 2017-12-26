# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 17:05:18 by fchevrey          #+#    #+#              #
#    Updated: 2017/12/22 20:01:02 by overetou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf

LIB = libft.a

SRC = ft_printf.c

OBJ = ft_printf.o

FLAG = -Werror -Wextra -Wall 

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(LIB)
	@clang -c main.c $(SRC) -I libft/
	@clang -o $(NAME) main.o $(OBJ) -I libft/ -L libft/ -lft
	./$(NAME)

$(LIB):
	@make -C libft/

clean:
	make -C libft/	fclean

fclean: clean
	rm -f $(NAME)

cleanall:
	rm libft/*.o
	rm libft/$(LIB)

re: fclean all
