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

FUNC = src/ft_printf.c

FLAG = -Werror -Wextra -Wall 

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME):
	@clang -c main.c -I includes/ 
	@clang -o $(NAME) main.o $(FUNC) -I libft/ -L libft/ -lft
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
