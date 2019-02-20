/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_field.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 15:36:34 by fgaribot          #+#    #+#             */
/*   Updated: 2019/02/20 19:02:16 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_field(t_data **data)
{
	(*data)->field = ft_atoi((*data)->format + (*data)->j);
	while (ft_isdigit((*data)->format[(*data)->j]) == 1)
		(*data)->j += 1;
}
