/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countdigits_base.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 18:20:35 by fgaribot          #+#    #+#             */
/*   Updated: 2019/02/11 18:38:20 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


long long	ft_countdigits_base(long long n, int base)
{
	int		count;

	count = 0;
	if (n == 0)
		count = 1;
	while (n != 0)
	{
		n = n / base;
		count++;
	}
	return (count);
}
