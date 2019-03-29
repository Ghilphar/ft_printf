#include <stdio.h>
#include "ft_printf.h"
#include "./libft/libft.h"

int main(){

int     nb;
char    c;
nb = 0;
c = 'W';

printf("%5p\n", &nb);     ft_printf("%5p\n", &nb);
printf("%-15p\n", &nb);   ft_printf("%-15p\n", &nb);
printf("%-5p\n", &nb);    ft_printf("%-5p\n", &nb);
printf("%42p\n", &nb);    ft_printf("%42p\n", &nb);
printf("%-18p\n", &nb);   ft_printf("%-18p\n", &nb);
printf("%42p\n", &nb);    ft_printf("%42p\n", &nb);
printf("%5p\n", &c);      ft_printf("%5p\n", &c);
printf("%-15p\n", &c);    ft_printf("%-15p\n", &c);
printf("%-5p\n", &c);     ft_printf("%-5p\n", &c);
printf("%42p\n", &c);     ft_printf("%42p\n", &c);
printf("%-18p\n", &c);    ft_printf("%-18p\n", &c);
printf("%42p\n", &c);     ft_printf("%42p\n", &c);













}