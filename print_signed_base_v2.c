/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 16:15:07 by fgaribot          #+#    #+#             */
/*   Updated: 2019/02/14 07:24:16 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		test1(t_data ****data, long long nb, char *base)
{
	int		tab[100];
	int		b;
	int		j;

	j = 1;
	tab[0] = 0;
	(***data)->neg = 1;
	if (nb <= 0)
	{
		nb = -nb;
		(***data)->neg = -1;
		if (nb == 0)
			(***data)->neg = 0;
	}
	b = ft_strlen(base);
	(***data)->digits = ft_countdigits_base(nb, b);
	return (b);
}

void	test2(t_data ****data)
{
	if ((***data)->precision != 0)
		(***data)->zero = 0;
	if ((***data)->precision < (***data)->digits)
		(***data)->precision = (***data)->digits;
	(***data)->field -= (***data)->precision;
	while ((***data)->field > 1 && (***data)->minus == 0)
	{
		if ((***data)->zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		(***data)->field -= 1;
		(***data)->i += 1;
	}
}

void	test3(t_data ****data)
{
	if ((***data)->neg == -1 || (***data)->plus == 1 ||
			(***data)->zero == 1 || (***data)->space == 1 || (***data)->field == 1)
	{
		(***data)->i += 1;
		(***data)->field -= 1;
	}
	if ((***data)->neg == -1)
		ft_putchar('-');
	else if ((***data)->plus == 1 && (***data)->neg >= 0)
		ft_putchar('+');
	else if ((***data)->zero == 1)
		ft_putchar('0');
	else if (((***data)->space == 1 || (***data)->field == 0) && (***data)->minus == 0)
		ft_putchar(' ');
	else
	{
		(***data)->field += 1;
		(***data)->i -= 1;
	}
	while ((***data)->precision > (***data)->digits)
	{
		ft_putchar('0');
		(***data)->i += 1;
		(***data)->precision--;
	}
}

void	test4(t_data ****data)
{
	while ((***data)->field > 0 && (***data)->minus == 1)
	{
		ft_putchar(' ');
		(***data)->field -= 1;
		(***data)->i += 1;
	}	
}

void	print_signed_base(long long nb, char *base, t_data ***data)
{
	int		tab[100];
	char		tab2[100];
	int		b;
	int		j;
	int		i;

	j = 0;
	i = 0;
	b = test1(&data, nb, base);
	while (nb != 0)
	{
		tab[j] = nb % b;
		nb = nb / b;
		j++;
	}
	(**data)->i += (**data)->digits;
	test2(&data);
	test3(&data);
	while (--j >= 0)
		tab2[i++] = base[tab[j]];
	tab2[i] = '\0';
	if ((**data)->neg == 0)
		ft_putchar('0');
	ft_putstr(tab2);
	test4(&data);
}
