# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/20 04:50:38 by fgaribot          #+#    #+#              #
#    Updated: 2019/01/20 23:23:54 by fgaribot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I ./includes
AR = ar rc
SRC = ./
FILES = $(SRC)flag_s.c\
		$(SRC)flag_di.c\
		$(SRC)flag_c.c\
		$(SRC)flag_u.c\
		$(SRC)flag_o.c\
		$(SRC)flag_xX.c\
		$(SRC)flag_h.c\
		$(SRC)flag_l.c\
		$(SRC)decimal_print_base.c\
		$(SRC)ft_printf.c

OBJ = $(FILES:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
	ranlib $(NAME)

clean :
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
