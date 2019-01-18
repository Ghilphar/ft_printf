/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 11:37:53 by fgaribot          #+#    #+#             */
/*   Updated: 2019/01/16 15:37:15 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	define_fonction(void (**ptr)())
{
	ptr[0] = ft_putnbr;
	ptr[1] = ft_putstr;
}

int	flags(char c)
{
	char	*flag;
	int	i;

	i = 0;
	flag = "ds";
	while (c != flag[i])
		i++;
	return (c == flag[i] ? 1 : 0);
}

void	init_struct(t_struct *data, char *str)
{
	(*data).i = 0;
	data->error = 0;
}

int	ft_printf(const char *format, ...)
{
	t_struct	data;

	int		i;
	init_struct(&data, str);
	va_start(data.arg, str);
	define_fonciton(data.ptr);
	while (*format != '\0')
	{
		i = ft_countchar(format, '%')
		write(1, format, i);
		format += i;
		if (*format == '%' && flags(*(format + 1) == 1))
		{
			call_fonction(format[data.i + 1], data.ptr, data.arg);
			data.i = data.i 
		}
	}
}
