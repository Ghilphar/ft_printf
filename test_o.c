#include <stdio.h>
#include "ft_printf.h"
#include "./libft/libft.h"

int main()
{
    int nb = 45;

    printf("%d\n", ft_printf("test o:%o\n", nb)); printf("%d\n", printf("test o:%o\n", nb));
    printf("%d\n", ft_printf("hash:%#o\n", nb)); printf("%d\n", printf("hash:%#o\n", nb));
    printf("%d\n", ft_printf("precision / grande:%.5o\n", nb));printf("%d\n", printf("precision / grande:%.5o\n", nb));
    printf("%d\n", ft_printf("precision / petite:%.0o\n", nb));printf("%d\n", printf("precision / petite:%.0o\n", nb));
    printf("%d\n", ft_printf("Prec + hash / grande:%#.5o\n", nb));printf("%d\n", printf("Prec + hash / grande:%#.5o\n", nb));
    printf("%d\n", ft_printf("Prec + hash / petite:%#.1o\n", nb));printf("%d\n", printf("Prec + hash / petite:%#.1o\n", nb));
    printf("%d\n", ft_printf("Prec + 0:%0.5o\n", nb));printf("%d\n", printf("Prec + 0:%0.5o\n", nb));
    printf("%d\n", ft_printf("Prec + minus:%-.5o\n", nb));printf("%d\n", printf("Prec + minus:%-.5o\n", nb));
    printf("%d\n", ft_printf("Size:%5o\n", nb));printf("%d\n", printf("Size:%5o\n", nb));
    printf("%d\n", ft_printf("size + prec:%7.3o\n", nb));printf("%d\n", printf("size + prec:%7.3o\n", nb));
    printf("%d\n", ft_printf("size + minus:%-5o\n", nb));printf("%d\n", printf("size + minus:%-5o\n", nb));
    printf("%d\n", ft_printf("size + zero:%05o\n", nb));printf("%d\n", printf("size + zero:%05o\n", nb));
    printf("%d\n", ft_printf("size + zero + hash:%#05o\n", nb));printf("%d\n", printf("size + zero + hash:%#05o\n", nb));
    printf("%d\n", ft_printf("size + zero + prec:%05.3o\n", nb));printf("%d\n", printf("size + zero + prec:%05.3o\n", nb));
    printf("%d\n", ft_printf("size + minus + prec:%-5.3o\n", nb));printf("%d\n", printf("size + minus + prec:%-5.3o\n", nb));
    printf("%d\n", ft_printf("size + hash + zero + prec:%#05.3o\n", nb));printf("%d\n", printf("size + hash + zero + prec:%#05.3o\n", nb));
    printf("%d\n", ft_printf("size + hash + zero + prec:%0#5.3o\n", nb));printf("%d\n", printf("size + hash + zero + prec:%0#5.3o\n", nb));
    printf("%d\n", ft_printf("size + hash + minus + prec:%-#7.3o\n", nb));printf("%d\n", printf("size + hash + minus + prec:%-#7.3o\n", nb));

    printf("\n%.3o", nb);
    return(0);
}