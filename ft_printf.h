/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 02:22:14 by fgaribot          #+#    #+#             */
/*   Updated: 2019/01/20 21:30:30 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <inttypes.h>

typedef struct		s_data
{
	int				i;
	int				casth;
	const char		*format;
	int				j;
	int				precision;
}					t_data;

va_list				*flag_h(va_list ap, t_data **data);
va_list				*flag_s(va_list ap, t_data **data);
va_list				*flag_di(va_list ap, t_data **data);
va_list				*flag_c(va_list ap, t_data **data);
va_list				*flag_u(va_list ap, t_data **data);
va_list				*flag_o(va_list ap, t_data **data);
va_list				*flag_x(va_list ap, t_data **data);
va_list				*flag_X(va_list ap, t_data **data);

void				exec_flag(char c, va_list ap, t_data *data);

typedef struct		s_func
{
	va_list 		*(*ptrfunc)(va_list ap, t_data **data);
	char			key;
}					t_func;

void				print_unsigned_base(size_t nb, char *base, t_data ***data);
void				print_signed_base(intmax_t nb, char *base, t_data ***data);
int					ft_printf(const char *format, ...);

#endif
