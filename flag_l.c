/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_l.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 23:11:42 by fgaribot          #+#    #+#             */
/*   Updated: 2019/02/21 12:16:00 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_l(t_data *data)
{
	if (data->castl == 0)
		data->castl = 1;
	else if (data->castl == 1)
		data->castl = 2;
	data->j += 1;
}
