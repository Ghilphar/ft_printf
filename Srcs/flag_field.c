/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_field.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 15:36:34 by fgaribot          #+#    #+#             */
/*   Updated: 2019/11/03 23:21:25 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	flag_field(t_data *data)
{
	data->field = ft_atoi(data->format + data->j);
	while (ft_isdigit(data->format[data->j]) == 1)
		data->j += 1;
}
