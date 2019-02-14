/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_xX.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 09:22:55 by fgaribot          #+#    #+#             */
/*   Updated: 2019/02/14 04:43:01 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

va_list *flag_x(va_list ap, t_data **data)
{
	(*data)->specifier = 'x';
	if ((*data)->casth != 0)
	{
		if ((*data)->casth == 1)
			print_unsigned_base((unsigned short)va_arg(ap, unsigned int),
					"0123456789abcdef", &data);
		if ((*data)->casth == 2)
			print_unsigned_base((unsigned char)va_arg(ap, unsigned int),
					"0123456789abcdef", &data);
		return (0);
	}
	if ((*data)->castl != 0)
	{
		if ((*data)->castl == 1)
			print_unsigned_base((unsigned long)va_arg(ap, unsigned long),
					"0123456789abcdef", &data);
		if ((*data)->castl == 2)
			print_unsigned_base((unsigned long long)va_arg(ap, unsigned long long), "0123456789abcdef", &data);
		return (0);
	}
	print_unsigned_base(va_arg(ap, unsigned int), "0123456789abcdef", &data);
	return (0);
}

va_list *flag_X(va_list ap, t_data **data)
{
	(*data)->specifier = 'X';
	if ((*data)->casth != 0)
	{
		if ((*data)->casth == 1)
			print_unsigned_base((unsigned short)va_arg(ap, unsigned long long),
					"0123456789ABCDEF", &data);
		if ((*data)->casth == 2)
			print_unsigned_base((unsigned char)va_arg(ap, unsigned long long),
					"0123456789ABCDEF", &data);
		return (0);
	}
	if ((*data)->castl != 0)
	{
		if ((*data)->castl == 1)
			print_unsigned_base((unsigned long)va_arg(ap, unsigned long),
					"0123456789ABCDEF", &data);
		if ((*data)->castl == 2)
			print_unsigned_base((unsigned long long)va_arg(ap, unsigned long long),
					"0123456789ABCDEF", &data);
		return (0);
	}
	print_unsigned_base(va_arg(ap, unsigned int), "0123456789ABCDEF", &data);
	return (0);
}
