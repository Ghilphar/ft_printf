/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 04:46:33 by fgaribot          #+#    #+#             */
/*   Updated: 2019/02/20 17:22:27 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_str(char *s, t_data ***data)
{
	int i;

	if (!s)
	{
		write(1, "(null)", 6);
		(**data)->i += 6;
		return ;
	}
	i = ft_strlen(s);
	if ((**data)->precision > i || (**data)->precision == -1)
		(**data)->precision = i;
	while ((**data)->field > (**data)->precision)
	{
		ft_putchar(' ');
		(**data)->field -= 1;
		(**data)->i += 1;
	}
	if ((**data)->precision < i && (**data)->precision != -1)
	{
		write(1, s, (**data)->precision);
		(**data)->i += (**data)->precision;
	}
	else
	{
		write(1, s, i);
		(**data)->i += i;
	}
}

va_list	*flag_s(va_list ap, t_data **data)
{
	(*data)->specifier = 's';
	print_str(va_arg(ap, char*), &data);
	return (0);
}
