/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_print_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 09:18:16 by fgaribot          #+#    #+#             */
/*   Updated: 2019/04/01 15:11:46 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_base(t_data *data, unsigned long long nb, char *base)
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

void		print_field(t_data *data, int j) {
    if (data->precision != -1)
        data->zero = 0;
    if ((data->precision == 0 && j == 0) && (data->specifier == 'o' || data->specifier == 'u' || data->specifier == 'x' || data->specifier == 'X'))
        data->pass = 666;
	if (data->precision < data->digits && data->pass != 666)
		data->precision = data->digits;
    if (data->sharp == 1)
    {
        if ((data->precision == 0 && data->specifier == 'o') || (data->specifier == 'o' && j != 0))
        {
            if (data->precision != data->digits && data->pass != 666)
                data->precision -= 1;
            data->i += 1;
            data->field -= 1;
        }
        else if ((data->specifier == 'x' || data->specifier == 'X') && j != 0)
        {
            data->i += 2;
            data->field -= 2;
        }
    }
    data->field -= data->precision;
    while(data->field > 0 && data->minus == 0 && data->zero == 0)
    {
        ft_putchar(' ');
        data->field -= 1;
        data->i += 1;
    }
	if (data->sharp == 1)
		print_sharp(data, j);
	while (data->field > 0 && data->minus == 0 && data->zero == 1)
	{
	    ft_putchar('0');
		data->field -= 1;
		data->i += 1;
	}
	while (data->precision > data->digits)
	{
		ft_putchar('0');
		data->i += 1;
		data->precision--;
	}
	if (data->neg == 0 && data->precision != 0)
	{
        ft_putchar('0');
        data->i += 1;
    }
}

void		test_4(t_data *data)
{
	while (data->field > 0 && data->minus == 1)
	{
		ft_putchar(' ');
		data->field -= 1;
		data->i += 1;
	}
}

void		print_sharp(t_data *data, int j)
{
	if ((data->precision == 0 && data->specifier == 'o') || (data->specifier == 'o' && j != 0))
	    ft_putchar('0');
	else if (data->specifier == 'x' && j != 0)
		ft_putstr("0x");
	else if (data->specifier == 'X' && j != 0)
		ft_putstr("0X");
}

void		print_unsigned(unsigned long long nb, char *base, t_data *data)
{
	int		tab[100];
	char	tab2[100];
	int		b;
	int		j;
	int		i;

	j = 0;
	i = 0;
	b = get_base(data, nb, base);
	while (nb != 0)
	{
		tab[j] = nb % b;
		nb = nb / b;
		j++;
	}
	if (j != 0)
	    data->i += data->digits;
	print_field(data, j);
    if (data->specifier == 'p')
    {
        ft_putstr("0x");
        data->i += 2;
    }
	while (--j >= 0)
		tab2[i++] = base[tab[j]];
	tab2[i] = '\0';
	ft_putstr(tab2);
	test_4(data);
}
