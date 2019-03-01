/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 16:15:07 by fgaribot          #+#    #+#             */
/*   Updated: 2019/02/25 18:23:25 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void        print_signed(unsigned long long nb, char *base, t_data *data)
{
	int     tab[100];
	char    tab2[100];
	int     b;
	int     j;
	int     i;

	j = 0;
	i = 0;
	b = test_1(data, nb, base);
	while (nb != 0)
	{
		tab[j] = nb % b;
		nb = nb / b;
		j++;
	}
	data->i += data->digits;
	if ((data->specifier == 'o' || data->specifier == 'x' ||
				data->specifier == 'X') && data->sharp == 1)
		test_3(data, j);
	test_2(data);
	while (--j >= 0)
		tab2[i++] = base[tab[j]];
	tab2[i] = '\0';
	ft_putstr(tab2);
	test_4(data);
}
