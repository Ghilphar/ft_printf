/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_print_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 09:18:16 by fgaribot          #+#    #+#             */
/*   Updated: 2019/02/02 16:49:53 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
void	print_unsigned_base(unsigned long long  nb, char *base, t_data ***data)
{
	int		tab[50];
	char	tab2[50];
	int		i;
	int		j;

	j = 0;
	i = ft_strlen(base);
	if (nb == 0)
	{
		ft_putchar('0');
		(**data)->i++;
	}
	while (nb != 0)
	{
		tab[j] = nb % i;
		nb = nb / i;
		j++;
	}
	(**data)->i += j;
	i = 0;
	while (--j >= 0)
		tab2[i++] = base[tab[j]];
	tab2[i] = '\0';
	ft_putstr(tab2);
}
*/

int             test_1(t_data ****data, long long nb, char *base)
{
	int             tab[100];
	int             b;
	int             j;

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

void    test_2(t_data ****data)
{
	if ((***data)->precision != 0)
		(***data)->zero = 0;
	if ((***data)->precision < (***data)->digits)
		(***data)->precision = (***data)->digits;
	(***data)->field -= (***data)->precision;
	while ((***data)->field > 0 && (***data)->minus == 0)
	{
		if ((***data)->zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		(***data)->field -= 1;
		(***data)->i += 1;
	}
}

void    test_3(t_data ****data)
{
/*
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
	else if ((***data)->space == 1 || (***data)->field == 0)
		ft_putchar(' ');
*/
	while ((***data)->precision > (***data)->digits)
	{
		ft_putchar('0');
		(***data)->i += 1;
		(***data)->precision--;
	}
}

void    test_4(t_data ****data)
{
	while ((***data)->field > 0 && (***data)->minus == 1)
	{
		ft_putchar(' ');
		(***data)->field -= 1;
		(***data)->i += 1;
	}
}

void	print_unsigned_base(unsigned long long nb, char *base, t_data ***data)
{
	int             tab[100];
	char            tab2[100];
	int             b;
	int             j;
	int             i;

	j = 0;
	i = 0;
	b = test_1(&data, nb, base);
	while (nb != 0)
	{
		tab[j] = nb % b;
		nb = nb / b;
		j++;
	}
	(**data)->i += (**data)->digits;
	test_2(&data);
	test_3(&data);
	while (--j >= 0)
		tab2[i++] = base[tab[j]];
	tab2[i] = '\0';
	if ((**data)->neg == 0)
		ft_putchar('0');
	ft_putstr(tab2);
	test_4(&data);
}
