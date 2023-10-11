#include <stdlib.h>
#include <stdio.h>

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

static int ft_set(char c, char const *set)
{
    size_t i;

    i = 0;
    while (set[i])
    {
        if (set[i] == c)
            return (1);
        i++;
    }
    return (0);
}

char *ft_strtrim(char const *s1, char const *set)
{
    char *str;
    size_t i;
    size_t start;
    size_t end;

    start = 0;
    while (s1[start] && ft_set(s1[start], set))
        start++;
    end = ft_strlen(s1);
    while (end > start && ft_set(s1[end - 1], set))
        end--;
    str = (char *)malloc(sizeof(*s1) * (end - start + 1));
    if (!str)
        return (NULL);
    i = 0;
    while (start < end)
        str[i++] = s1[start++];
    str[i] = 0;
    return (str);
}

#include <stdio.h>
int main()
{
    char *strs = "hoodggg";
    char *str2 = "ohg";
    printf("%s\n", ft_strtrim(strs, str2));

    char *res = ft_strtrim(strs, str2);
    size_t i = 0;
    while (i <= ft_strlen(res))
    {
        if (res[i] == '\0')
        {
            printf("i: %i gg: %c\n", i, res[i]);
        }
        printf("i: %i c: %c\n", i, res[i]);
        i++;
    }
}