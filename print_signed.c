/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 08:52:33 by fgaribot          #+#    #+#             */
/*   Updated: 2019/04/19 16:55:53 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_signed(long long nb, char *base, t_data *data)
{
	int		tab[100];
	char	tab2[100];
	int		b;
	int		j;
	int		i;

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
