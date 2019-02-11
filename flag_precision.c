/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 15:44:52 by fgaribot          #+#    #+#             */
/*   Updated: 2019/02/11 14:21:45 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_precision(t_data **data)
{
	(*data)->j += 1;
	(*data)->precision = ft_atoi((*data)->format + (*data)->j);
	while (ft_isdigit((*data)->format[(*data)->j]) == 1)
		(*data)->j += 1;
}
