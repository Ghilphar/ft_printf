/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 10:58:06 by fgaribot          #+#    #+#             */
/*   Updated: 2019/02/21 11:06:25 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include "./libft/libft.h"

int main ()
{
	char 	*i = NULL;

	ft_printf("%-#6o|\n", 2500);
	ft_printf("%X\n", 4294967296);
	ft_printf("%x\n", 42);
	ft_printf("%o\n", 40);
	ft_printf("%hhX\n", 4294967296);
	ft_printf("%10.7s\n", "chien");
	printf("%10.7s\n", "chien");
	return(0);
}
