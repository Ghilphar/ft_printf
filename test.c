#include "./includes/ft_printf.h"
#include <stdio.h>

int main (int ac, char **av)
{
    printf("\n%d\n", printf("%-10.2ls!!", 0x45));
    // printf("\n");
    // printf("\n%d\n",ft_printf("test %-7C %007d%-10.2ls!!", 0xd777, 0x45, L"〻"));
    // printf("\n%d\n",ft_printf("test %-7C %007d%-10.2ls!!", 0xd777, 0x45, L"〻"));

    printf("\n%d\n",ft_printf("%-10.2ls!!", 0x45));
    printf("\n");

    return (1);
}