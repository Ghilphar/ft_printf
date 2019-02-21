/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 08:52:33 by fgaribot          #+#    #+#             */
/*   Updated: 2019/02/21 10:39:20 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_signed(long long nb, char *base, t_data **data)
{
	int		tab[100];
	char	tab2[100];
	int		b;
	int		j;
	int		i;

	j = 0;
	i = 0;
	b = test1(&*data, nb, base);
	while (nb != 0)
	{
		tab[j++] = nb % b;
		nb = nb / b;
	}
	(*data)->i += (*data)->digits;
	test2(&*data);
	test3(&*data);
	test34(&*data);
	while (--j >= 0)
		tab2[i++] = base[tab[j]];
	tab2[i] = '\0';
	if ((*data)->neg == 0)
		ft_putchar('0');
	ft_putstr(tab2);
	test4(&*data);
}
