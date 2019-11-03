# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/20 04:50:38 by fgaribot          #+#    #+#              #
#    Updated: 2019/11/03 23:18:41 by fgaribot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft
DIR_S = srcs
DIR_O = obj
HEADER = includes
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC = ./srcs/

SOURCES = 	flag_s.c\
			flag_di.c\
			flag_c.c\
			flag_u.c\
			flag_o.c\
			flag_x.c\
			flag_h_v2.c\
			flag_l_v2.c\
			flag_p.c\
			flag_f.c\
			flag_f_2.c\
			flags.c\
			list_flag.c\
			flag_field.c\
			flag_precision.c\
			decimal_print_base.c\
			print_signed_base_v2.c\
			print_signed.c\
			ft_printf.c\
			print_percentage.c\
			flag_long_double.c\
			list_specifier.c\
			decimal_print_base_anex.c

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
		$(SRC)/decimal_print_base_anex.c

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all : $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "libftprintf.a successfully created"

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADER)/ft_printf.h
	@mkdir -p obj
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

clean :
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)
	@echo "libftprintf clean OK"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)
	@echo "libftprintf fclean OK"

re: fclean all
