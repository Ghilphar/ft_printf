/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 16:15:07 by fgaribot          #+#    #+#             */
/*   Updated: 2019/02/22 17:21:37 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int			test1(t_data *data, long long nb, char *base)
{
	int		b;
	int		j;

	j = 1;
	data->neg = 1;
	if (nb <= 0)
	{
		nb = -nb;
		data->neg = -1;
		if (nb == 0)
			data->neg = 0;
	}
	b = ft_strlen(base);
	data->digits = ft_countdigits_base(nb, b);
	return (b);
}

void		test2(t_data *data)
{
	if (data->precision != -1)
		data->zero = 0;
	if (data->precision < data->digits)
		data->precision = data->digits;
	data->field -= data->precision;
	if (data->zero == 1 && data->minus == 0)
		test3(data);
	while (data->field > 1 && data->minus == 0)
	{
		if (data->zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		data->field -= 1;
		data->i += 1;
	}
	if (data->zero == 1)
		ft_putchar('0');
}

void		test3(t_data *data)
{
	if (data->neg == -1 || data->plus == 1 ||
			data->zero == 1 || data->space == 1 ||
			data->field == 1)
	{
		data->i += 1;
		data->field -= 1;
	}
	if (data->neg == -1)
		ft_putchar('-');
	else if (data->plus == 1 && data->neg >= 0)
		ft_putchar('+');
	else if (data->zero == 1)
		ft_putchar('0');
	else if ((data->space == 1 || data->field == 0) &&
			data->minus == 0)
		ft_putchar(' ');
	else
	{
		data->field += 1;
		data->i -= 1;
	}
}

void		test34(t_data *data)
{
	while (data->precision > data->digits)
	{
		ft_putchar('0');
		data->i += 1;
		data->precision--;
	}
}

void		test4(t_data *data)
{
	while (data->field > 0 && data->minus == 1)
	{
		ft_putchar(' ');
		data->field -= 1;
		data->i += 1;
	}
}
