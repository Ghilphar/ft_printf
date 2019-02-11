/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 16:15:07 by fgaribot          #+#    #+#             */
/*   Updated: 2019/02/11 17:28:30 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
   void		print_signed_base(long long nb, char *base, t_data ***data)
   {
   int		tab[100];
   char	tab2[100];
   int		i;
   int		j;

   j = 0;
   i = ft_strlen(base);
   (**data)->i += nb < 0 ? 1 : 0;
   nb < 0 ? ft_putchar('-') : 1;
   nb = nb < 0 ? -nb : nb;
   nb == 0 ? ft_putchar('0') : 1;
   (**data)->i += nb == 0 ? 1 : 0;
   while (nb != 0)
   {
   tab[j] = nb % i;
   nb = nb / i;
   j++;
   }
   (**data)->i += j;
   i = 0;
   while (--j >= 0)
   tab2[i++] = base[tab[j]];
   tab2[i] = '\0';
   ft_putstr(tab2);
   }

   void	flgs(t_data ****data, int **tab)
   {
   int		digits;

   if ((***data)->field <= (***data)->precision)
   (***data)->field = 0;

   }
   */

int		test1(t_data ****data, long long nb, char *base)
{
	int		tab[100];
	int		b;
	int		j;

	j = 1;
	tab[0] = 0;
	(***data)->neg = 1;
	if (nb <= 0)
	{
		nb = -nb;
		(***data)->neg = -1;
		if (nb == 0)
			(***data)->neg = 0;
	}
	b = ft_strlen(base);
	(***data)->digits = ft_countdigits_base(nb, b);
	/*
	while (nb != 0)
	{
		tab[j] = nb % b;
		nb = nb / b;
		tab[0] += 1;
	}
	(***data)->i += (***data)->digits;
	return (tab);
	*/
	return (b);
}

void	test2(t_data ****data)
{
	if ((***data)->precision != 0)
		(***data)->zero = 0;
	if ((***data)->precision < (***data)->digits)
		(***data)->precision = (***data)->digits;
	(***data)->field -= (***data)->precision;
	while ((***data)->field > 1 && (***data)->minus == 0)
	{
		if ((***data)->zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		(***data)->field -= 1;
		(***data)->i += 1;
	}
}

void	test3(t_data ****data)
{
	if ((***data)->neg == -1 || (***data)->plus == 1 ||
			(***data)->zero == 1 || (***data)->space == 1 || (***data)->field == 1)
	{
		(***data)->i += 1;
		(***data)->field -= 1;
	}
	if ((***data)->neg == -1)
		ft_putchar('-');
	else if ((***data)->plus == 1 && (***data)->neg >= 0)
		ft_putchar('+');
	else if ((***data)->zero == 1)
		ft_putchar('0');
	else if ((***data)->space == 1 || (***data)->field == 0)
		ft_putchar(' ');
}
/*
void	test4(t_data ****data)
{

}
*/
void	print_signed_base(long long nb, char *base, t_data ***data)
{
	int		tab[100]; // int	*tab;
//	int		*tab;
	char	tab2[100];
	int		b;       //
	int		j;       //
//	int		digits;  //
//	int		neg;     // 
	int		i;

	j = 0;
	i = 0;
	b = test1(&data, nb, base);                    /* Remplace 
	neg = 1;                         
	if (nb <= 0)
	{
		neg = -1;
		nb = -nb;
		if (nb == 0)
			neg = 0;
	}
	b = ft_strlen(base);
	digits = ft_countdigits_base(nb, b);            */
	while (nb != 0)
	{
		tab[j] = nb % b;
		nb = nb / b;
		j++;
	}
	(**data)->i += (**data)->digits;/*
	while (nb != 0)
	{
		tab[j] = nb % b;
		nb = nb / b;
		j++;
	}
	(**data)->i += digits;                             TEST1       */   
	test2(&data);									/* REMPPLACE
	if ((**data)->precision != 0)
		(**data)->zero = 0;
	if ((**data)->precision < digits)
		(**data)->precision = digits;
	(**data)->field -= (**data)->precision;
	while (((**data)->field > 1) && (**data)->minus == 0 && (**data)->zero == 1)
	{
		ft_putchar('0');
		(**data)->field -= 1;
		(**data)->i += 1;
	}	
	while ((**data)->field > 1 && (**data)->minus == 0)
	{
		ft_putchar(' ');
		(**data)->field -= 1;
		(**data)->i += 1;
	}											TEST2			*/
	test3(&data);								/* REMPLACE
	if (neg == -1)
	{
		ft_putchar('-');
		(**data)->i += 1;
		(**data)->field -= 1;
	}
	else if ((**data)->plus == 1 && neg == 1)
	{
		ft_putchar('+');
		(**data)->i += 1;
		(**data)->field -= 1;
	}
	else if ((**data)->zero == 1)
	{
		ft_putchar('0');
		(**data)->i += 1;
		(**data)->field -= 1;
	}
	else if ((**data)->space == 1 || (**data)->field == 1)
	{
		ft_putchar(' ');
		(**data)->i += 1;
		(**data)->field -= 1;
	}                                        TEST3            */
	while ((**data)->precision > (**data)->digits)
	{
		ft_putchar('0');
		(**data)->i += 1;
		(**data)->precision--;
	}
//	while (--j >= 0)
	while (--j >= 0)
	{
		tab2[i++] = base[tab[j]];
	}
	tab2[i] = '\0';
	if ((**data)->neg == 0)       //
		ft_putchar('0');
//	if (neg == 0)
//		ft_putchar('0');
	ft_putstr(tab2);
//	test4(&data);									REMPLACE 
	while ((**data)->field > 0 && (**data)->minus == 1)
	{
		ft_putchar(' ');
		(**data)->field -= 1;
		(**data)->i += 1;
	}	
}
