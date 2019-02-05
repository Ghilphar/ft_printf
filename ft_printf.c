/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 11:37:53 by fgaribot          #+#    #+#             */
/*   Updated: 2019/02/04 17:17:43 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_func	g_tab[] =
{
	{&flag_di, 'd'},
	{&flag_di, 'i'},
	{&flag_s, 's'},
	{&flag_c, 'c'},
	{&flag_u, 'u'},
	{&flag_o, 'o'},
	{&flag_x, 'x'},
	{&flag_X, 'X'},
	{&flag_h, 'h'},
	{&flag_p, 'p'},
	{NULL, -1}
};

void	exec_flag(char c, va_list ap, t_data *data)
{
	int i;

	i = 0;
	while (g_tab[i].key != -1)
	{
		if (g_tab[i].key == c)
			g_tab[i].ptrfunc(ap, &data);
		i++;
	}
}

void	ft_init_data(t_data *data, const char **format)
{
	data->format = *format;
	data->i = 0;
	data->j = 0;
	data->casth = 0;
	data->zero = 0;
}

void	analyse_flags(t_data *data)
{
	while (data->format[data->j] == '+' || data->format[data->j] == '-' ||
			data->format[data->j] == '#' || data->format[data->j] == ' ' ||
			data->format[data->j] == '0')
	{
		data->zero = data->format[data->j] == '0' ? 1 : data->zero;
		data->plus = data->format[data->j] == '+' ? 1 : data->plus;
		data->minus = data->format[data->j] == '-' ? 1 : data->minus;
		data->sharp = data->format[data->j] == '#' ? 1 : data->sharp;
		data->space = data->format[data->j] == ' ' ? 1 : data->space;
		data->j += 1;
	}
	data->field = ft_isdigit(data->format[data->j]) == 1 ?
		ft_atoi(data->format + j) : data->field;
	while (ft_isdigit(data->format[data->j]) == 1)
		data->j += 1;
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	t_data	data;

	ft_init_data(&data, &format);
	va_start(ap, format);
	while (format[data.j] != '\0')
	{
		if (format[data.j] == '%')
		{
			data.j++;
			analyse_flags(&data);
			if (format[data.j] != '%')
				exec_flag(format[data.j++], ap, &data);
		}
		if (format[data.j] != '\0')
		{
			ft_putchar(format[data.j++]);
			data.i += 1;
		}
	}
	va_end(ap);
	return (data.i);
}
