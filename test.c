/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 10:58:06 by fgaribot          #+#    #+#             */
/*   Updated: 2019/02/22 16:22:55 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include "./libft/libft.h"

int main ()
{
	char 	*i = NULL;

	printf("%-8s\n", "chien");
	ft_printf("%-8s\n", "chien");

//	printf("%i|", ft_printf("%X\n", 4294967296));
//	printf("%i|", ft_printf("%x\n", 42));
//	printf("%i|", ft_printf("%o\n", 40));
//	printf("%i|", ft_printf("%hhX\n", 4294967296));
//	printf("%i|", ft_printf("%10.7s\n", "chien"));
	return(0);
}
