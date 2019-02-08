/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 10:58:06 by fgaribot          #+#    #+#             */
/*   Updated: 2019/02/06 18:02:58 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./libft/libft.h"

int		find_flag(char c);

int main ()
{
	int		i = 2;
	char	*man;
	if (i == 2)
		exit(0);
	if (i == 1)
		i = 2;
	else
		i = 1;
	ft_putnbr(i);
	return(0);
}
