/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 10:58:06 by fgaribot          #+#    #+#             */
/*   Updated: 2019/03/01 12:04:30 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include "./libft/libft.h"

int main ()
{
	printf("%d\n", printf("%lu", -42));
	//printf("%d\n", ft_printf("@moulitest: %o %0o\n", 0, 0));
	//printf("%d\n", printf("@moulitest: %o %0o\n", 0, 0));
	return(0);
}
