/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 10:58:06 by fgaribot          #+#    #+#             */
/*   Updated: 2019/02/04 15:11:45 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./libft/libft.h"

int main ()
{
	int		j;
	char	*str;

	str = "00123.1frg3143";
	ft_putnbr(ft_atoi(str));
	ft_putchar('\n');
	return (0);
}
