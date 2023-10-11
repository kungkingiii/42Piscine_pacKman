void ft_striteri(char *s, void (*f)(unsigned int, char *))
{
    unsigned int i;

    if (!s)
        return;
    i = 0;
    while (s[i])
    {
        f(i, &s[i]);
        ++i;
    }
}

#include <stdio.h>
void ft_gen(unsigned int index, char *str)
{
    *str += '0' + index;
}

int main()
{
    char input[] = "bvb ccgg";

    ft_striteri(input, ft_gen);

    printf("Result: %s\n", input);
}
