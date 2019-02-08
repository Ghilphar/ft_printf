/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 08:45:36 by fgaribot          #+#    #+#             */
/*   Updated: 2019/02/08 14:43:47 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

va_list	*flag_u(va_list ap, t_data **data)
{
	if ((*data)->casth != 0)
	{
		if ((*data)->casth == 1)
			print_signed_base((unsigned short)va_arg(ap, unsigned int),
					"0123456789", &data);
		if ((*data)->casth == 2)
			print_signed_base((unsigned char)va_arg(ap, unsigned int),
					"0123456789", &data);
		return (0);
	}
	if ((*data)->castl != 0)
	{
		if ((*data)->castl == 1)
			print_signed_base((unsigned long)va_arg(ap, unsigned long),
					"0123456789", &data);
		if ((*data)->castl == 2)
			print_signed_base((unsigned long long)va_arg(ap, unsigned long),
					"0123456789", &data);
		return (0);
	}
	/*
	   if ((*data)->casth == 1)
	   {
	   print_unsigned_base((unsigned short)va_arg(ap, unsigned int),
	   "0123456789", &data);
	   (*data)->casth = 0;
	   return (0);
	   }
	   if ((*data)->casth == 2)
	   {
	   print_unsigned_base((unsigned char)va_arg(ap, unsigned int),
	   "0123456789", &data);
	   (*data)->casth = 0;
	   return (0);
	   }
	   */
	print_unsigned_base(va_arg(ap, unsigned int), "0123456789", &data);
	return (0);
}
