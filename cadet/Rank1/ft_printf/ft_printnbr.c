#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>
#include <stdio.h>

static int numlen(int n, int base)
{
    int i;

    i = 0;
    if (n < 10)
        return (1);
    while (n > 0)
    {
        n = n / base;
        i++;
    }
    return (i);
}

static char *strgen(char *s, int len, int n)
{
    int i;
    int r;

    i = len - 1;
    r = n;
    if (n == -2147483648)
        r = 147483648;
    if (n < 0 && n != -2147483648)
        r = n * -1;
    while (i >= 0)
    {
        if (i == 0 && n < 0)
            s[i] = '-';
        else if (i == 1 && n == -2147483648)
            s[i] = '2';
        else if (r >= 10)
        {
            s[i] = r % 10 + '0';
            r = r / 10;
        }
        else
            s[i] = r + '0';
        i--;
    }
    return (s);
}

char *ft_itoa(int n)
{
    int len;
    int t;
    char *s;

    t = n;
    if (n == -2147483648)
        t = 147483648;
    if (n < 0 && n != -2147483648)
        t = n * -1;
    len = numlen(t, 10);
    if (n == -2147483648)
        len = len + 2;
    if (n < 0 && n != -2147483648)
        len = len + 1;
    s = (char *)malloc((len + 1) * sizeof(char));
    if (!s)
        return (0);
    strgen(s, len, n);
    s[len] = '\0';
    return (s);
}

int ft_putint(int n)
{
    int len;
    char *num;
    int tmp;

    len = 0;
    num = ft_itoa(n);
    tmp = ft_putstr(num);
    if (tmp == -1)
        return (-1);
    len = tmp;
    free(num);
    return (len);
}

int ft_num_len(unsigned int num)
{
    int len;

    len = 0;
    while (num != 0)
    {
        len++;
        num = num / 10;
    }
    return (len);
}

char *ft_uitoa(unsigned int n)
{
    char *num;
    int len;

    len = ft_num_len(n);
    num = (char *)malloc(sizeof(char) * (len + 1));
    if (!num)
        return (0);
    num[len] = '\0';
    while (n != 0)
    {
        num[len - 1] = n % 10 + 48;
        n = n / 10;
        len--;
    }
    return (num);
}

int ft_putunsigned_int(unsigned int n)
{
    int print_length;
    char *num;

    print_length = 0;
    if (n == 0)
        print_length += write(1, "0", 1);
    else
    {
        num = ft_uitoa(n);
        print_length += ft_putstr(num);
        free(num);
    }
    return (print_length);
}