/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 10:58:06 by fgaribot          #+#    #+#             */
/*   Updated: 2019/03/19 20:06:31 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include "./libft/libft.h"

int main ()
{
	int nb = 12;

	ft_printf("%x\n", nb); printf("   |   ") ; printf("%x\n", nb);
	ft_printf("test X:%X\n", nb); printf("   |   ") ; printf("test X:%X\n", nb);
	ft_printf("Hash:%#X\n", nb); printf("   |   ") ; printf("Hash:%#X\n", nb);
	ft_printf("prec / grande:%.5X\n", nb); printf("   |   ") ; printf("prec / grande:%.5X\n", nb);
	ft_printf("prec / petite:%.0X\n", nb); printf("   |   ") ; printf("prec / petite:%.0X\n", nb);
	ft_printf("hash + prec / grande:%#.5X\n", nb); printf("   |   ") ; printf("hash + prec / grande:%#.5X\n", nb);
	ft_printf("hash + prec / petite:%#.1X\n", nb); printf("   |   ") ; printf("hash + prec / petite:%#.1X\n", nb);
	ft_printf("prec + 0: %0.5X\n", nb); printf("   |   ") ; printf("prec + 0: %0.5X\n", nb);
	ft_printf("Prec + minus:%-.5X\n", nb); printf("   |   ") ; printf("Prec + minus:%-.5X\n", nb);
	ft_printf("size:%5X\n", nb); printf("   |   ") ; printf("size:%5X\n", nb);
	ft_printf("size + prec:%7.3X\n", nb); printf("   |   ") ; printf("size + prec:%7.3X\n", nb);
	ft_printf("size + mminus:%-5X\n", nb); printf("   |   ") ; printf("size + mminus:%-5X\n", nb);
	ft_printf("size + 0:%05X\n", nb); printf("   |   ") ; printf("size + 0:%05X\n", nb);
	ft_printf("size + 0 + hash:%#05X\n", nb); printf("   |   ") ; printf("size + 0 + hash:%#05X\n", nb);
	ft_printf("size + 0 + prec:%05.3X\n", nb); printf("   |   ") ; printf("size + 0 + prec:%05.3X\n", nb);
	ft_printf("size + minus + prec:%-5.3X\n", nb); printf("   |   ") ; printf("size + minus + prec:%-5.3X\n", nb);
	ft_printf("size + hash + 0 + prec:%#05.3X\n", nb); printf("   |   ") ; printf("size + hash + 0 + prec:%#05.3X\n", nb);
	ft_printf("size + hash + 0 + prec:%0#5.3X\n", nb); printf("   |   ") ; printf("size + hash + 0 + prec:%0#5.3X\n", nb);
	ft_printf("size + hash + minus + prec:%-#7.3X\n", nb); printf("   |   ") ; printf("size + hash + minus + prec:%-#7.3X\n", nb);

	return (0);
}
