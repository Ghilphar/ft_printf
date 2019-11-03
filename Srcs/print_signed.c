/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 08:52:33 by fgaribot          #+#    #+#             */
/*   Updated: 2019/11/02 19:03:16 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void		print_signed(long long nb, char *base, t_data *data)
{
	int		tab[100];
	char	tab2[100];
	int		b;
	int		j;
	int		i;

	// printf("field = %d\n, precision = %d\n", data->field, data->precision);
	j = 0;
	i = 0;
	b = check_nb(data, nb, base);
	if (nb < 0)
		nb = -nb;
	while (nb != 0)
	{
		tab[j++] = nb % b;
		nb = nb / b;
	}
	print_fill(data);
	print_prec(data);
	while (--j >= 0)
		tab2[i++] = base[tab[j]];
	tab2[i] = '\0';
	if (data->neg == 0)
		ft_putchar('0');
	ft_putstr(tab2);
	print_min(data);
}
