# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/20 04:50:38 by fgaribot          #+#    #+#              #
#    Updated: 2019/04/19 16:37:37 by fgaribot         ###   ########.fr        #
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
		$(SRC)flag_f.c\
		$(SRC)flags.c\
		$(SRC)list_flag.c\
		$(SRC)flag_field.c\
		$(SRC)flag_precision.c\
		$(SRC)decimal_print_base.c\
		$(SRC)print_signed_base_v2.c\
		$(SRC)print_signed.c\
		$(SRC)ft_printf.c\
		$(SRC)/libft/ft_putstr.c\
		$(SRC)/libft/ft_strlen.c\
		$(SRC)/libft/ft_putchar.c\
		$(SRC)/libft/ft_atoi.c\
		$(SRC)/libft/ft_countdigits_base.c\
		$(SRC)/libft/ft_countdigits.c\
		$(SRC)/libft/ft_isdigit.c\
		$(SRC)/libft/ft_itoa.c\
		$(SRC)/libft/ft_strrev.c\
		$(SRC)/libft/ft_putstr.c\
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
