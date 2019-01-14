/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 11:37:53 by fgaribot          #+#    #+#             */
/*   Updated: 2019/01/14 18:12:48 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void    ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	if (n >= 0 && n < 10)
		ft_putchar(n + '0');
	if (n < 0 && n != -2147483648)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

/*
char	*translate(unsigned int num, int base)
{
	static char buff[33];
	char 		*ptr;

	ptr = &buff[sizeof(buff) - 1];
	*ptr = '\0';
	do{
		*--ptr = "0123456789abcdef"[num % base];
		num /= base;
	} 
	while (num != 0);

	return (ptr);
}
*/

int		ft_printf(const char *format, ...)
{
	va_list 	argp;
	const char	*ptr;
	int			i;

	ptr = format;
	va_start(argp, format);
	while (*ptr != '\0')
	{
		i = ft_countchar(ptr, '%');
		write(1, ptr, i);
		ptr += (i);                                                         // Le pointeur est sur le % possibilite de l'envoyer sur une autre fonction pour le traiter.
		if (*ptr == '%' && (*(ptr + 1) == 'd'))
		{
			ft_putnbr(va_arg(argp, int));
			ptr += 2;
		}																	// Il faut renvoyer le pointeur a la fin du flag.
	}
	va_end(argp);
	return (0);
}


int main()
{
	ft_printf("un : %d, deux : %d, et trois int : %d\n fe", 15, 150, 666);
}
