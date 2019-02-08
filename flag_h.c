/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_h.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 19:18:33 by fgaribot          #+#    #+#             */
/*   Updated: 2019/02/07 09:05:21 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

va_list	*flag_h(va_list ap, t_data **data)
{
	char	*flag;
	int		i;

	i = 0;
	flag = "diouxXh|";
	while ((*data)->format[(*data)->j] != flag[i] && flag[i] != '|' &&
			(*data)->format[(*data)->j] != '\0')
		i++;
	if (i < 7)
	{
		if ((*data)->casth == 1)
			(*data)->casth = 2;
		else
			(*data)->casth = 1;
		exec_specifier((*data)->format[((*data)->j)++], ap, &(**data));
	}
	if (flag[i] == '|')
		exit(EXIT_FAILURE);
	return (0);
}
