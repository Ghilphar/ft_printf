/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 05:02:48 by fgaribot          #+#    #+#             */
/*   Updated: 2019/01/20 23:33:19 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

int main()
{
	ft_putnbr(printf("s : %s \n d : %ld c: %c, u: %lu, o: %lo, x: %lx, X: %lX, %%\n", "chien", (long)150,320, (unsigned long)-1, (unsigned long)-1,(unsigned long)-1, (unsigned long)-1));
	ft_putchar('\n');
	ft_putnbr(ft_printf("s : %s \n d : %ld c: %c, u: %lu, o: %lo, x: %lx, X: %lX, %%\n", "chien", (long)150,320, (unsigned long)-1, (unsigned long)-1,(unsigned long)-1,     (unsigned long)-1));
	return (0);
}
