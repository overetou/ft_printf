# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: overetou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 12:25:00 by overetou          #+#    #+#              #
#    Updated: 2018/01/05 13:30:18 by overetou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Werror -Wextra

CC = gcc

LIB_PATH = ./libft/

SRC_PATH = ./src/

LIB_FILE = ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
  	ft_isdigit.c ft_isprint.c ft_itoa.c ft_memalloc.c ft_memccpy.c \
	ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c \
	ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c \
	ft_putendl_fd.c ft_putnbr_fd.c \
	ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c \
	ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c \
	ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c \
	ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c \
	ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c \
	ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c \
	ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c \
	ft_toupper.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
	ft_lstadd.c ft_lstiter.c ft_lstmap.c \
	ft_lstpushback.c ft_lstaddlink.c \
	ft_atoi.c ft_lstaddnext.c \
	ft_power.c ft_makestr.c \
	ft_strfuse.c

SRC_FILE = ft_printf.c ft_nbr_to_str.c ft_addchar.c ft_unbr_to_str.c \
	ft_char_to_str.c ft_strnput.c ft_putnbr_lhex.c ft_putnbr_l.c \
	ft_putnbr_loct.c ft_putunbr_l.c ft_putwstr.c ft_process_flag.c \
	ft_putstr.c ft_putnbr.c ft_putnbr_oct.c ft_putnbr_mhex.c \
	ft_putunbr.c ft_putnbr_hex.c ft_putwchar.c


SRC = $(addprefix $(SRC_PATH), $(SRC_FILE))

OBJ = $(LIB_FILE:.c=.o) $(SRC_FILE:.c=.o)

LIB = $(addprefix $(LIB_PATH), $(LIB_FILE))

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c $(SRC) -I ./inc
	$(CC) $(CFLAGS) -c $(LIB) -I $(LIB_PATH)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
