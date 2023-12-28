#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>
#include <stdio.h>

int ft_ptr_len(uintptr_t num)
{
    int len;

    len = 0;
    while (num != 0)
    {
        len++;
        num = num / 16;
    }
    return (len);
}

void ft_put_ptr(uintptr_t num)
{
    if (num >= 16)
    {
        ft_put_ptr(num / 16);
        ft_put_ptr(num % 16);
    }
    else
    {
        if (num <= 9)
            ft_putchar(num + '0');
        else
            ft_putchar(num - 10 + 'A');
    }
}

int ft_putptr(unsigned long long ptr)
{
    int print_length;

    print_length = 0;
    print_length += write(1, "00", 2);
    if (ptr == 0)
        print_length += write(1, "0", 1);
    else
    {
        ft_put_ptr(ptr);
        print_length += ft_ptr_len(ptr);
    }
    return (print_length);
}