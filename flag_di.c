/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 05:18:47 by fgaribot          #+#    #+#             */
/*   Updated: 2019/01/22 10:24:20 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_signed_base(long long nb, char *base,t_data ***data)
{
	int     tab[100];
	char    tab2[100];
	int     i;
	int     j;

	j = 0;
	i = ft_strlen(base);
	(**data)->i += nb < 0 ? 1 : 0;
	nb < 0 ? ft_putchar('-') : 1;
	nb = nb < 0 ? -nb : nb;
	nb == 0 ? ft_putchar('0') : 1;
	(**data)->i += nb == 0 ? 1 : 0;
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

va_list	*flag_di(va_list ap, t_data **data)
{
	if ((*data)->casth == 1)
	{
		print_signed_base((short)va_arg(ap, int), "0123456789", &data);
		(*data)->casth = 0;
		return (0);
	}
	if ((*data)->casth == 2)
	{
		print_signed_base((signed char)va_arg(ap, int), "0123456789", &data);
		(*data)->casth = 0;
		return (0);
	}
	if ((*data)->castl == 1)
	{
		print_signed_base((long)va_arg(ap, long), "0123456789", &data);
		(*data)->castl = 0;
		return (0);
	}
	if ((*data)->castl == 2)
	{
		print_signed_base((long long)va_arg(ap, long long), "0123456789", &data);
		(*data)->castl = 0;
		return (0);
	}
	print_signed_base(va_arg(ap, int), "0123456789", &data);
	return (0);
}
