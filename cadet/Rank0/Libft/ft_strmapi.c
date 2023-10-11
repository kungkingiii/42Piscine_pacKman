#include <stdlib.h>

size_t ft_strlen(const char *s)
{
    int i;

    i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char *str;
    unsigned int i;

    if (!s)
        return (0);
    str = malloc(sizeof(char) * (ft_strlen(s) + 1));
    if (!str)
        return (0);
    i = 0;
    while (s[i])
    {
        str[i] = f(i, s[i]);
        ++i;
    }
    str[i] = '\0';
    return (str);
}

#include <stdio.h>
char ft_gen(unsigned int index, char c)
{
    printf("%c\n", c + index);
    return c + index;
}

int main()
{
    printf("%s\n", ft_strmapi("sad bvb", ft_gen));
}
