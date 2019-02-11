/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 05:24:04 by fgaribot          #+#    #+#             */
/*   Updated: 2019/02/11 16:07:06 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

va_list	*flag_c(va_list ap, t_data **data)
{
	int				i;
	unsigned int	j;

	(*data)->specifier = 'c';
	i = va_arg(ap,int);
	j = (unsigned int)i;
	(*data)->i += 1;
	ft_putchar(j);
	return (0);
}
