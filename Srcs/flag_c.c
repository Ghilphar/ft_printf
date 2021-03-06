/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 05:24:04 by fgaribot          #+#    #+#             */
/*   Updated: 2019/11/03 23:22:19 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void				print_c(unsigned char j, t_data *data)
{
	while (data->field > 1 && data->minus == 0)
	{
		ft_putchar(' ');
		data->field -= 1;
		data->i += 1;
	}
	ft_putchar(j);
	data->i += 1;
	while (data->field > 1 && data->minus == 1)
	{
		ft_putchar(' ');
		data->field -= 1;
		data->i += 1;
	}
}

va_list				*flag_c(va_list ap, t_data *data)
{
	int				i;
	unsigned int	j;

	data->spe = 'c';
	i = va_arg(ap, int);
	j = (unsigned int)i;
	print_c(j, data);
	return (0);
}
