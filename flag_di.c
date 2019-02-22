/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 05:18:47 by fgaribot          #+#    #+#             */
/*   Updated: 2019/02/22 16:32:20 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

va_list	*flag_di(va_list ap, t_data *data)
{
	data->specifier = 'd';
	if (data->casth != 0)
	{
		if (data->casth == 1)
			print_signed((short)va_arg(ap, int), "0123456789", data);
		if (data->casth == 2)
			print_signed((signed char)va_arg(ap, int),
					"0123456789", data);
		return (0);
	}
	if (data->castl != 0)
	{
		if (data->castl == 1)
			print_signed((long long)va_arg(ap, long), "0123456789", data);
		if (data->castl == 2)
			print_signed((long long)va_arg(ap, long long),
					"0123456789", data);
		return (0);
	}
	print_signed(va_arg(ap, int), "0123456789", data);
	return (0);
}
