# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/20 04:50:38 by fgaribot          #+#    #+#              #
#    Updated: 2019/02/14 08:57:20 by fgaribot         ###   ########.fr        #
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
		$(SRC)flag_x.c\
		$(SRC)flag_h_v2.c\
		$(SRC)flag_l_v2.c\
		$(SRC)flag_p.c\
		$(SRC)flags.c\
		$(SRC)list_flag.c\
		$(SRC)flag_field.c\
		$(SRC)flag_precision.c\
		$(SRC)decimal_print_base.c\
		$(SRC)print_signed_base_v2.c\
		$(SRC)print_signed.c\
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
