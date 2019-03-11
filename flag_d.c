/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 14:33:41 by fgaribot          #+#    #+#             */
/*   Updated: 2019/03/11 19:08:39 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnchar(char c, int	n)
{
	char buffer[256];
	int	i;

	i = 0;
	while(n-- > 0)
	{
		buffer[i++] = c;
		if (i == 255)
		{
			i = 0;
			ft_putstr(buffer);
		}
	}
	if (i != 0)
		ft_putstr(buffer);
}

int		ft_countdigits_ull(unsigned long long n)
{
	int					count;

	count = 0;
	if (n == 0)
		count = 1;
	while (n != 0)
	{
		n = n / 10;
		count++;	
	}
	return (count);
}

void	correct_flag(unsigned long long n, t_data *data)
{
	if (data->plus == 1 || data->neg == -1)
	{
		data->field_2 += 1;
		data->space = 0;
	}
	if (data->neg == -1)
		data->plus = 0;
	if (data->minus == 1)
		data->zero = 0;
	data->digits = ft_countdigits_ull(n);
	if (data->digits > data->precision && (n != 0 && data->precision != 0))
		data->field_2 += data->digits;
	else
		data->field_2 += data->precision;
	if (data->space == 1)
	{
		data->field_2 += 1;
		write(1, " ", 1);
		data->i += 1;
	}
}

void	print_field_sign(t_data *data)
{
	int		i;

	i = data->field - data->field_2;
	if (i > 0 && (data->zero == 0 && data->minus == 0))
	{
		ft_putnchar(' ', i);
		data->i += i;
	}
	if (data->plus == 1)
	{
		write(1, "+", 1);
		data->i += 1;
	}
	if (data->neg == -1)
	{
		write(1, "-", 1);
		data->i += 1;
	}
	if (i > 0 && data->zero == 1)
	{
		ft_putnchar('0', i);
		data->i += i;
	}
}

char	*ft_itoa_llu(unsigned long long n)
{
	char	*str;
	int		i;
	int		nb;

	i = 0;
	nb = ft_countdigits(n);
	if (!(str = (char *)malloc(sizeof(*str) *  (nb + 2))))
		return (NULL);
	while (nb-- > 0)
	{
		str[i++] = (n % 10) + 48;
		n = n / 10;
	}
	str[i] = '\0';
	return (ft_strrev(str));
}

void	print_minus(t_data *data)
{
	int					i;

	i = data->field - data->field_2;
	data->i += i;
	ft_putnchar(' ', i);
}

void	print_d(unsigned long long n, t_data *data)
{
	char				*nb;
	int					i;

	correct_flag(n, data);
	print_field_sign(data);
	nb = ft_itoa_llu(n);
	i = data->precision - data->digits;
	if (data->precision > data->digits)
	{
		ft_putnchar('0', i);
		data->i += i;
	}
	if (!(data->precision == 0 && n == 0))
	{
		data->i += data->digits;
		ft_putstr(nb);
	}
	free(nb);
	if (data->minus == 1)
		print_minus(data);
}

void	print_d2(long long nb, t_data *data)
{
	unsigned long long n;
	if (nb < 0)
	{
		data->neg = -1;
		n = -nb;
	}
	else
		n = nb;
	print_d(n, data);
}

va_list *flag_d(va_list ap, t_data *data)
{
	data->specifier = 'd';
	if (data->casth != 0)
	{
		if (data->casth == 1)
			print_d2((short)va_arg(ap, int), data);
		if (data->casth == 2)
			print_d2((signed char)va_arg(ap, int), data);
		return (0);
	}
	if (data->castl != 0)
	{
		if (data->castl == 1)
			print_d2((long long)va_arg(ap, long), data);
		if (data->castl == 2)
			print_d2((long long)va_arg(ap, long long), data);
		return (0);
	}
	print_d2(va_arg(ap, int), data);
	return (0);
}
