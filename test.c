/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 10:58:06 by fgaribot          #+#    #+#             */
/*   Updated: 2019/03/11 20:38:31 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include "./libft/libft.h"
#include "ft_printf_test.h"

int main ()
{
	int nb = 56432;

//	ft_printf("min long long :  %20lld\n",LLONG_MIN);

	ft_printf("%lld\n", -9223372036854775808);
//	printf("min long long :  %25lld\n",LLONG_MIN);

	return (0);
}
