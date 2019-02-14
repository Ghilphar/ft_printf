/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 05:37:34 by fgaribot          #+#    #+#             */
/*   Updated: 2019/02/14 08:36:00 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

va_list			*flag_p(va_list ap, t_data **data)
{
	uintptr_t	adress;

	(*data)->specifier = 'p';
	adress = (uintptr_t)(va_arg(ap, void*));
	ft_putstr("0x");
	(*data)->i += 2;
	print_unsigned(adress, "0123456789abcdef", &data);
	return (0);
}
