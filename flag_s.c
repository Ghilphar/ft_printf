/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 04:46:33 by fgaribot          #+#    #+#             */
/*   Updated: 2019/02/11 16:08:19 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_str(char *s, t_data ***data)
{
	int i;

	i = ft_strlen(s);
	(**data)->i += i;
	if (!s)
		return ;
	write(1, s, i);
}


va_list *flag_s(va_list ap, t_data **data)
{
	(*data)->specifier = 's';
	print_str(va_arg(ap, char*), &data);
	return (0);
}
