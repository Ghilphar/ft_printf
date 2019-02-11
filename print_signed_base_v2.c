/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 16:15:07 by fgaribot          #+#    #+#             */
/*   Updated: 2019/02/08 20:00:31 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_signed_base(long long nb, char *base, t_data ***data)
{
	int		tab[100];
	char	tab2[100];
	int		i;
	int		j;

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

void	flgs(t_data ****data, int **tab)
{
	int		digits;

	if ((***data)->field <= (***data)->precision)
		(***data)->field = 0;

}

void	print_signed_base(long long nb, char *base, t_data ***data)
{
	int		tab[100];
	char	tab2[100];
	int		b;
//	int		j;
	int		digits;
	int		neg;
	int		i;

//	j = 0;
	if (nb < 0)
	{
		neg = -1;
		nb = -nb;
	}
	b = ft_strlen(base);
	digits = ft_countdigits_base(nb, b);
	while (nb != 0)
	{
		tab[j] = nb % b;
		nb = nb / b;
//		j++;
	}
	(**data)->i += digits;
	(**data)->field -= digits;
	while ((**data)->field > ((**data)->precision + 1) &&
		(**data)->minus == 0 && (**data)->zero == 0)
	{
		ft_putchar(' ');
		(**data)->field -= 1;
		(**data)->i += 1;
	}	
	if ((**data)->plus == 1 || (**data)->space == 1 || neg == -1)
	{
		if (neg == -1)
			ft_putchar('-');
		else if ((**data)->plus == 1 && neg == 0)
			ft_putchar('+');
		else if ((**data)->space == 1 && neg == 0)
			ft_putchar(' ');
		else if (((**data)->field > (**data)->precision) &&
			((**data)->minus == 0) && ((**data)->zero == 0))
			ft_putchar(' ');
		while ((**data)->)
		(**data)->i += 1;
		(**data)->field -= 1;
		if ((**data)->field
	}
	
}
