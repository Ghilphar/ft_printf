/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 09:00:46 by fgaribot          #+#    #+#             */
/*   Updated: 2019/02/14 08:13:29 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

va_list		*flag_o(va_list ap, t_data **data)
{
	(*data)->specifier = 'o';
	if ((*data)->casth != 0)
	{
		if ((*data)->casth == 1)
			print_unsigned((unsigned short)va_arg(ap, unsigned int),
					"01234567", &data);
		if ((*data)->casth == 2)
			print_unsigned((unsigned char)va_arg(ap, unsigned int),
					"01234567", &data);
		return (0);
	}
	if ((*data)->castl != 0)
	{
		if ((*data)->castl == 1)
			print_unsigned((unsigned long)va_arg(ap, unsigned long long),
					"01234567", &data);
		if ((*data)->castl == 2)
			print_unsigned((unsigned long long)va_arg(ap, unsigned long long),
					"01234567", &data);
		return (0);
	}
	print_unsigned(va_arg(ap, unsigned int), "01234567", &data);
	return (0);
}
