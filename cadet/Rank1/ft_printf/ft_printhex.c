int count_hex(int n)
{
    int count;

    count = 0;
    while (n > 0)
    {
        n = n / 16;
        count++;
    }
    return count;
}

char check_hex(int h, char f)
{
    if (h > 9)
    {
        if (f == 'x')
            return (h - 10 + 'a');
        if (f == 'X')
            return (h - 10 + 'A');
    }
    return (h + '0');
}

char *dec_to_hex(int n, char f, int hexlen)
{
    int i;
    char *s;

    i = hexlen - 1;
    s = (char *)malloc((hexlen) * sizeof(char));
    while (i >= 0)
    {
        if (n > 0)
            s[i] = check_hex(n % 16, f);
        else
            s[i] = check_hex(n / 16, f);
        n = n / 16;
        i--;
    }
    s[hexlen] = '\0';
    return s;
}

int ft_puthex_int(int n, char f)
{
    int hexlen;
    char *hex;

    hexlen = count_hex(n);
    printf("origin%d\n", hexlen);
    hex = dec_to_hex(n, f, hexlen);
    hexlen += ft_putstr(hex);
    free(hex);
    return (hexlen);
}
