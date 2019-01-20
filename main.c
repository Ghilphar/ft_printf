/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 05:02:48 by fgaribot          #+#    #+#             */
/*   Updated: 2019/01/20 22:39:20 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

int main()
{
	ft_putnbr(printf("s : %s \n d : %hhd c: %c, u: %hhu, o: %hho, x: %hhx, X: %hhX, %%\n", "chien", (char)150,320, (unsigned char)50, (unsigned char)20000000,(unsigned char)150, (unsigned char)250));
	ft_putchar('\n');
	ft_putnbr(ft_printf("s : %s \n d : %hd c: %c, u: %hu, o: %ho, x: %hx, X: %hX, %%\n", "chien", (char)150,320, (unsigned char)50, (unsigned char)20000000,(unsigned char)150, (unsigned char)250));
	return (0);
}
