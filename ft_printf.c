/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 11:37:53 by fgaribot          #+#    #+#             */
/*   Updated: 2019/01/20 22:34:49 by fgaribot         ###   ########.fr       */
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

void	flag(const char *format)
{
	if (*format == '-')
		ft_putchar('-');
	if (*format == '#')
	{
		format++;
		if (*format == 'o') 
			ft_putchar('0');
		if (*format == 'x')
			ft_putstr("0x");
		if (*format == 'X')
			ft_putstr("0X");
		format--;
	}
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	t_data	data;

	data.format = format;
	data.i = 0;
	data.casth = 0;
	data.j = 0;
	va_start(ap, format);
	while (format[data.j] != '\0')
	{
		if (format[data.j] == '%')
		{
			if (format[++data.j] == '#')
				flag(format + data.j++);
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
