/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_print_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 09:18:16 by fgaribot          #+#    #+#             */
/*   Updated: 2019/02/20 18:57:14 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			test_1(t_data **data, unsigned long long nb, char *base)
{
	int		tab[100];
	int		b;
	int		j;

	j = 1;
	tab[0] = 0;
	(*data)->neg = 1;
	if (nb <= 0)
	{
		nb = -nb;
		(*data)->neg = -1;
		if (nb == 0)
			(*data)->neg = 0;
	}
	b = ft_strlen(base);
	(*data)->digits = ft_countdigits_base(nb, b);
	return (b);
}

void		test_2(t_data **data)
{
	if ((*data)->precision != -1)
		(*data)->zero = 0;
	if ((*data)->precision < (*data)->digits)
		(*data)->precision = (*data)->digits;
	(*data)->field -= (*data)->precision;
	while ((*data)->field > 0 && (*data)->minus == 0)
	{
		if ((*data)->zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		(*data)->field -= 1;
		(*data)->i += 1;
	}
	while ((*data)->precision > (*data)->digits)
	{
		ft_putchar('0');
		(*data)->i += 1;
		(*data)->precision--;
	}
	if ((*data)->neg == 0)
		ft_putchar('0');
}

void		test_4(t_data **data)
{
	while ((*data)->field > 0 && (*data)->minus == 1)
	{
		ft_putchar(' ');
		(*data)->field -= 1;
		(*data)->i += 1;
	}
}

void		test_3(t_data **data, int j)
{
	if ((*data)->specifier == 'o' && j != 0)
	{
		ft_putchar('0');
		(*data)->field -= 1;
		(*data)->i += 1;
	}
	else if ((*data)->specifier == 'x' && j != 0)
	{
		ft_putstr("0x");
		(*data)->field -= 2;
		(*data)->i += 2;
	}
	else if ((*data)->specifier == 'X' && j != 0)
	{
		ft_putstr("0X");
		(*data)->field -= 2;
		(*data)->i += 2;
	}
}

void		print_unsigned(unsigned long long nb, char *base, t_data **data)
{
	int		tab[100];
	char	tab2[100];
	int		b;
	int		j;
	int		i;

	j = 0;
	i = 0;
	b = test_1(&*data, nb, base);
	while (nb != 0)
	{
		tab[j] = nb % b;
		nb = nb / b;
		j++;
	}
	(*data)->i += (*data)->digits;
	test_2(&*data);
	if (((*data)->specifier == 'o' || (*data)->specifier == 'x' ||
				(*data)->specifier == 'X') && (*data)->sharp == 1)
		test_3(&*data, j);
	while (--j >= 0)
		tab2[i++] = base[tab[j]];
	tab2[i] = '\0';
	ft_putstr(tab2);
	test_4(&*data);
}
