/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_print_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 09:18:16 by fgaribot          #+#    #+#             */
/*   Updated: 2019/01/20 22:54:05 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_unsigned_base(size_t nb, char *base, t_data ***data)
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
