/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_print_base_anex.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 15:58:56 by fgaribot          #+#    #+#             */
/*   Updated: 2019/04/19 16:30:33 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_pointer(t_data *data)
{
	if (data->spe == 'p')
	{
		ft_putstr("0x");
		data->i += 2;
	}
}

void	print_sharp(t_data *data, int j)
{
	if ((data->precision == 0 && data->spe == 'o')
			|| (data->spe == 'o' && j != 0))
		ft_putchar('0');
	else if (data->spe == 'x' && j != 0)
		ft_putstr("0x");
	else if (data->spe == 'X' && j != 0)
		ft_putstr("0X");
}
