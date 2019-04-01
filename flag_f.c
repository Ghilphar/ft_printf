/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:02:28 by fgaribot          #+#    #+#             */
/*   Updated: 2019/04/01 15:29:50 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_float(double n, t_data *data)
{
	long long	nbr;

	if (data->precision == -1)
		data->precision = 6;
	if (n < 0)
	{
		n = -n;
		data->neg = -1;
	}
	nbr = (long long)n;
	data->digits = ft_countdigits_base(nbr, 10);
	data->i += data->digits;
	while (data->field > (data->digits + 1 + precision) && data->minus == 0 && data->zero == 0)
	{
		ft_putchar(' ');
		data->field -= 1;
		data->i += 1;
	}
	while (data->field > (data->digits + 1 + precision) && data->minus == 0 && data->zero == 1)
	{
		ft_putchar('0');
		data->field -= 1;
		data->i += 1;
	}
	ft_putllnbr(nbr);
}



va_list	*flag_f(va_list ap, t_data *data)
{
	data->specifier = 'f';
	print_float(va_arg(ap, double), data);
	return (0);
}
