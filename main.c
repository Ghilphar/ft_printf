/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 05:02:48 by fgaribot          #+#    #+#             */
/*   Updated: 2019/01/22 10:25:45 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

int main()
{
	ft_putnbr(printf("s : %s \n d : %ld c: %c, u: %llu, o: %llo, x: %llx, X: %llX, %%\n", "chien", (long)-9223372036854775807,320, (unsigned long long)-1, (unsigned long long)-1,(unsigned long long)-1, (unsigned long long)-1));
	ft_putchar('\n');
	ft_putnbr(ft_printf("s : %s \n d : %ld c: %c, u: %llu, o: %llo, x: %llx, X: %llX, %%\n", "chien", (long)-9223372036854775807,320, (unsigned long long)-1, (unsigned long long)-1,(unsigned long long)-1,     (unsigned long long)-1));
	return (0);
}
