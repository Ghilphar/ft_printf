/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 02:22:14 by fgaribot          #+#    #+#             */
/*   Updated: 2019/02/08 16:18:10 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <inttypes.h>
# include <stdlib.h>

typedef struct		s_data
{
	int				i;
	int				casth;
	int				castl;
	const char		*format;
	int				j;
	int				zero;
	int				plus;
	int				minus;
	int				sharp;
	int				space;
	int				field;
	int				precision;
}					t_data;

va_list				*flag_h(va_list ap, t_data **data);
va_list				*flag_l(va_list ap, t_data **data);
va_list				*flag_s(va_list ap, t_data **data);
va_list				*flag_di(va_list ap, t_data **data);
va_list				*flag_c(va_list ap, t_data **data);
va_list				*flag_u(va_list ap, t_data **data);
va_list				*flag_o(va_list ap, t_data **data);
va_list				*flag_x(va_list ap, t_data **data);
va_list				*flag_X(va_list ap, t_data **data);
va_list				*flag_p(va_list ap, t_data **data);

void				exec_specifier(char c, va_list ap, t_data *data);
void				exec_flag(char c, t_data *data);

typedef struct		s_func
{
	va_list 		*(*ptrfunc)(va_list ap, t_data **data);
	char			key;
}					t_func;

typedef struct		s_flag
{
	void			(*ptrfunc)(t_data **data);
	char			key;
}					t_flag;

void				print_signed_base(long long nb, char *bas, t_data ***data);
void				print_unsigned_base(unsigned long long nb, char *base,
	   				t_data ***data);
void				print_signed_base(long long nb, char *base, t_data ***data);
int					list_flag(char c);
void				flag_sharp(t_data **data);
void				flag_zero(t_data **data);
void				flag_space(t_data **data);
void				flag_plus(t_data **data);
void				flag_minus(t_data **data);
void				flag_field(t_data **data);
void				flag_precision(t_data **data);
int					ft_printf(const char *format, ...);

#endif
