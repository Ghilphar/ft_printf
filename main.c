/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 05:02:48 by fgaribot          #+#    #+#             */
/*   Updated: 2019/02/08 15:13:13 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

int main()
{

	int		*in;
	long long 	l = 3000000000000;

	ft_putnbr(printf("%ld\n", 3000000000));
	ft_putchar('\n');

	ft_putnbr(printf("%p ; s : %s \n d : %d ld: %lld, u: %llu, o: %llo, x: %llx, X: %llX, %%\n", in, "chien", (char)150, l, (unsigned long long)50, (unsigned long long)20000000,(unsigned long long)150, (unsigned long long)250));
	ft_putchar('\n');
	ft_putnbr(ft_printf("%p ; s : %s \n d : %d ld: %lld, u: %llu, o: %llo, x: %llx, X: %llX, %%\n", in, "chien", (char)150, l, (unsigned long long)50, (unsigned long long)20000000,(unsigned long long)150, (unsigned long long)250));
	return (0);
}
