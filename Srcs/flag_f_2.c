/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_f_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:15:44 by fgaribot          #+#    #+#             */
/*   Updated: 2019/04/23 15:22:05 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_exponent(unsigned long long n)
{
	int			i;

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

char			*ftoa_decimal(long double n, t_data *data, char *dest, char *s)
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

char			*ftoa_integer(long double n, t_data *data, char *dest)
{
	long long	integer;
	int			i;
	char		*p;

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
	{
		*dest++ = '0';
		p++;
	}
	return (p);
}
