/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_h.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 19:18:33 by fgaribot          #+#    #+#             */
/*   Updated: 2019/01/20 22:37:21 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

va_list	*flag_h(va_list ap, t_data **data)
{
	char	*flag;
	int		i;

	i = 0;
	flag = "diouxXh";
	while ((*data)->format[(*data)->j] != flag[i] && flag[i] != '\0' &&
			(*data)->format[(*data)->j] != '\0')
		i++;
	if (i < 6)
	{
		(*data)->casth = 1;
		exec_flag((*data)->format[((*data)->j)++], ap, &(**data));
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
				(*data)->casth = 2;
				exec_flag((*data)->format[((*data)->j)++], ap, &(**data));
			}
		}
	return (0);
}
