/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 05:02:48 by fgaribot          #+#    #+#             */
/*   Updated: 2019/02/06 17:45:40 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

int main()
{

	int		*in;
	
	ft_putnbr(printf("% +-#", +15));
	ft_putchar('\n');
	
	ft_putnbr(printf("%p ; s : %s \n d : %10hhd c: %c, u: %hhu, o: %hho, x: %hhx, X: %hhX, %%\n", in, "chien", (char)150,320, (unsigned char)50, (unsigned char)20000000,(unsigned char)150, (unsigned char)250));
	ft_putchar('\n');
	ft_putnbr(ft_printf("%p ; s : %s \n d : %d c: %c, u: %hhu, o: %ho, x: %hx, X: %hX, %%\n", in, "chien", (char)150,320, (unsigned char)50, (unsigned char)20000000,(unsigned char)150, (unsigned char)250));
	return (0);
}
