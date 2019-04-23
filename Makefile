# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/20 04:50:38 by fgaribot          #+#    #+#              #
#    Updated: 2019/04/23 16:04:21 by fgaribot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I ./includes
AR = ar rc
SRC = ./Srcs/
FILES = $(SRC)flag_s.c\
		$(SRC)flag_di.c\
		$(SRC)flag_c.c\
		$(SRC)flag_u.c\
		$(SRC)flag_o.c\
		$(SRC)flag_x.c\
		$(SRC)flag_h_v2.c\
		$(SRC)flag_l_v2.c\
		$(SRC)flag_p.c\
		$(SRC)flag_f.c\
		$(SRC)flag_f_2.c\
		$(SRC)flags.c\
		$(SRC)list_flag.c\
		$(SRC)flag_field.c\
		$(SRC)flag_precision.c\
		$(SRC)decimal_print_base.c\
		$(SRC)print_signed_base_v2.c\
		$(SRC)print_signed.c\
		$(SRC)ft_printf.c\
		$(SRC)/ft_putstr.c\
		$(SRC)/ft_strlen.c\
		$(SRC)/ft_putchar.c\
		$(SRC)/ft_atoi.c\
		$(SRC)/ft_countdigits_base.c\
		$(SRC)/ft_countdigits.c\
		$(SRC)/ft_isdigit.c\
		$(SRC)/ft_itoa.c\
		$(SRC)/ft_strrev.c\
		$(SRC)/print_percentage.c\
		$(SRC)/decimal_print_base_anex.c\

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
