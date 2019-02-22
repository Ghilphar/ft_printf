/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 15:26:37 by fgaribot          #+#    #+#             */
/*   Updated: 2019/02/22 17:11:38 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_sharp(t_data *data)
{
	data->sharp = 1;
	data->j += 1;
}

void	flag_plus(t_data *data)
{
	data->plus = 1;
	data->j += 1;
}

void	flag_minus(t_data *data)
{
	data->minus = 1;
	data->j += 1;
}

void	flag_space(t_data *data)
{
	data->space = 1;
	data->j += 1;
}

void	flag_zero(t_data *data)
{
	data->zero = 1;
	data->j += 1;
}
