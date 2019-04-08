/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:02:28 by fgaribot          #+#    #+#             */
/*   Updated: 2019/04/08 17:56:23 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_fil(t_data *data)
{
	while (data->field > data->field_2 && data->minus == 0 && data->zero == 0)
	{
		ft_putchar(' ');
		data->field -= 1;
		data->i += 1;
	}
	while (data->field > data->field_2 && data->minus == 0 && data->zero == 1)
	{
		ft_putchar('0');
		data->field -= 1;
		data->i += 1;
	}
	if (data->neg == -1)
		ft_putchar('-');
	if (data->neg != 1 && data->plus == 1)
		ft_putchar('+');
}

int		ft_exponent(unsigned long long n)
{
	int i;

	i = 0;
	if (n == 0)
		i = 1;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

long double	correct_flags(long double n, t_data *data)
{
	data->specifier = 'f';
	if (data->plus == 1)
		data->space = 0;
	if (data->minus == 1)
		data->zero = 0;
	if (data->precision == -1)
		data->precision = 6;
	if (n < 0)
	{
		n = -n;
		data->neg = -1;
	}
	if (n == 0)
		data->neg = 0;
	data->digits = ft_exponent((unsigned long long)n);
	if (data->precision == 0)
		data->field_2 = data->digits;
	if (data->precision > 0)
		data->field_2 = data->precision + data->digits + 1;
	if (data->neg == -1 || data->plus == 1)
		data->field_2 += 1;
	data->i += data->field_2;
	return (n);
}

void		reverse(char *p, char *q)
{
	char c;

	while (p++ < q--)
	{
		c = *p;
		*p = *q;
		*q = c;
	}
}

char		*incr(char *s, char *f)
{
	int		co;
	char	*t = f;

	co = 1;
	while (t >= s && co == 1)
	{
		if (*t == '.')
			continue;
		*t += co;
		if (*t > '9')
			*t = '0';
		else
			co = 0;
		t--;
	}
	if (co)
	{
		t = ++f;
		while (t > s)
		{
			*t = *(t - 1);
			*s = '1';
			t--;
		}
	}
	return (f);
}

char		*ftoa_integer(long double n, t_data *data, char *dest)
{
	long long		integer;
	int				i;
	char			*p;

	p = dest;
	i = 0;
	integer = (long long)n;
	if (integer)
	{
		while (integer && i++ <= data->digits)
		{
			*p++ = ('0' + (integer % 10));
			integer /= 10;
		}
		reverse(dest, p - 1);
	}
	else
		*dest++ = '0';
//	if (data->precision == 0)
//		round_up();
	return (p);
}

char		*ftoa_decimal(long double n, t_data *data, char *dest, char *s)
{
	int			precision;
	long double	decimal;

	decimal = n - (long long)n;
	precision = data->precision;
	*dest++ = '.';
	while (precision)
	{
		decimal *= 10;
		*dest++ = '0' + (int)decimal;
		decimal -= (int)decimal;
		precision--;
	}
	decimal *= 10;
	if ((int)decimal > 5)
		dest = incr(s, dest - 1) + 1;
	return (dest);
}

va_list	*flag_f(va_list ap, t_data *data)
{
	long double		n;
	char			*save;
	char			*p;
	char			*s;

	n = va_arg(ap, long double);
	n = correct_flags(n, data);
	print_fil(data);
	if (!(save = (char *)malloc(sizeof(save) * (data->field_2 + 1))))
		return (NULL);
	p = save;
	s = save;
	p = ftoa_integer(n, data, p);
	if (data->precision != 0)
		p = ftoa_decimal(n, data, p, s);
	*p = '\0';
	ft_putstr(save);
	free(save);
	return (0);
}
