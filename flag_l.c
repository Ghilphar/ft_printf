/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_l.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 23:11:42 by fgaribot          #+#    #+#             */
/*   Updated: 2019/02/06 16:53:39 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

va_list	*flag_l(va_list ap, t_data **data)
{
	char    *flag;
	int     i;

	i = 0;
	flag = "diouxXl";
	while ((*data)->format[(*data)->j] != flag[i] && flag[i] != '\0' &&
			(*data)->format[(*data)->j] != '\0')
		i++;
	if (i < 6)
	{
		(*data)->castl = 1;
		exec_specifier((*data)->format[((*data)->j)++], ap, &(**data));
	}

	if (i == 6)
	{
		(*data)->j += 1;
		i = 0;
		while ((*data)->format[(*data)->j] != flag[i] && flag[i] !=
				'\0' && (*data)->format[(*data)->j] != '\0')
			i++;
		if (i < 6)
		{
			(*data)->castl = 2;
			exec_specifier((*data)->format[((*data)->j)++], ap, &(**data));
		}
	}
	return (0);
}
