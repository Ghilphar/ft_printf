/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 08:45:36 by fgaribot          #+#    #+#             */
/*   Updated: 2019/02/21 10:34:58 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

va_list		*flag_u(va_list ap, t_data **data)
{
	(*data)->specifier = 'u';
	if ((*data)->casth != 0)
	{
		if ((*data)->casth == 1)
			print_unsigned((unsigned short)va_arg(ap, unsigned int),
					"0123456789", &*data);
		if ((*data)->casth == 2)
			print_unsigned((unsigned char)va_arg(ap, unsigned int),
					"0123456789", &*data);
		return (0);
	}
	if ((*data)->castl != 0)
	{
		if ((*data)->castl == 1)
			print_unsigned((unsigned long)va_arg(ap, unsigned long),
					"0123456789", &*data);
		if ((*data)->castl == 2)
			print_unsigned((unsigned long long)va_arg(ap, unsigned long),
					"0123456789", &*data);
		return (0);
	}
	print_unsigned(va_arg(ap, unsigned int), "0123456789", &*data);
	return (0);
}
