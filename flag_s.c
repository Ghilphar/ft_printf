/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 04:46:33 by fgaribot          #+#    #+#             */
/*   Updated: 2019/04/19 16:36:46 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_realstr(t_data *data, char *s, int i)
{
	if (data->precision < i && data->precision != -1)
	{
		write(1, s, data->precision);
		data->i += data->precision;
	}
	else
	{
		write(1, s, i);
		data->i += i;
	}
}

void	print_str(char *s, t_data *data)
{
	int i;

	if (!s)
		s = "(null)";
	i = ft_strlen(s);
	if (data->precision > i || data->precision == -1)
		data->precision = i;
	while (data->field > data->precision && data->minus == 0)
	{
		ft_putchar(' ');
		data->field -= 1;
		data->i += 1;
	}
	print_realstr(data, s, i);
	while (data->field > data->precision && data->minus == 1)
	{
		ft_putchar(' ');
		data->field -= 1;
		data->i += 1;
	}
}

va_list	*flag_s(va_list ap, t_data *data)
{
	data->spe = 's';
	print_str(va_arg(ap, char*), data);
	return (0);
}
