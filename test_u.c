#include <stdio.h>
#include "ft_printf.h"
#include "./libft/libft.h"

int main () {
    int nb = 45;

    ft_printf("precision:%.5u|\n", nb);
    //printf("|");
    printf("precision:%.5u|\n", nb);
    ft_printf("Prec + 0:%0.5u|\n", nb);
    //printf("|");
    printf("Prec + 0:%0.5u|\n", nb);
    ft_printf("Prec + minus:%-.5u|\n", nb);
    //printf("|");
    printf("Prec + minus:%-.5u|\n", nb);
    ft_printf("size:%5u|\n", nb);
    //printf("|");
    printf("size:%5u|\n", nb);
    ft_printf("size + minus:%-5u|\n", nb);
    //printf("|");
    printf("size + minus:%-5u|\n", nb);
    ft_printf("size + 0:%05u|\n", nb);
    //printf("|");
    printf("size + 0:%05u|\n", nb);
    ft_printf("size + 0 + prec:%05.3u|\n", nb);
    //printf("|");
    printf("size + 0 + prec:%05.3u|\n", nb);
    ft_printf("size + minus + prec:%-5.3u|\n", nb);
    //printf("|");
    printf("size + minus + prec:%-5.3u|\n", nb);
    ft_printf("%-5.3u|\n", nb);
    //printf("|");
    printf("%-5.3u|\n", nb);
    ft_printf("|%050.u|\n", nb);
    //printf("|");
    printf("|%050.u|\n", nb);
    ft_printf("%-1.45u|\n", nb);
    //printf("|");
    printf("%-1.45u|\n", nb);
    ft_printf("%-55.35u|\n", nb);
    //printf("|");
    printf("%-55.35u|\n", nb);
}