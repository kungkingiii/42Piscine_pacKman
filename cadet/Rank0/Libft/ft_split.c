#include <stdlib.h>
#include <libft.h>

size_t ft_asize(char const *s, char c)
{
    size_t i;
    size_t count;

    i = 0;
    count = 0;
    while (s[i] != '\0')
    {
        if (s[i] == c && i != 0)
            count++;
        if (s[i + 1] == '\0' && s[i] != c)
            count++;
        i++;
    }
    return count;
}

size_t ft_counts(char const *s, char c, unsigned int start)
{
    size_t count;

    count = 0;
    while (s[start] != '\0')
    {
        if (s[start] == c)
        {
            return (count);
        }
        start++;
        count++;
    }
    return count;
}

size_t ft_start(char const *s, char c, unsigned int n)
{
    size_t i;
    size_t count;

    i = 0;
    count = 0;
    if (s[0] == c)
    {
        if (n == 1)
            return 1;
        else
            n = n + 1;
    }
    while (s[i] != '\0')
    {
        if (s[i] == c)
        {
            count++;
            if (count == n - 1)
                return (i + 1);
        }
        i++;
    }
    return (0);
}

char *ft_strgen(char const *s, char c, unsigned int n)
{
    size_t i;
    size_t start;
    size_t total;
    char *ptr;

    i = 0;
    start = ft_start(s, c, n);
    total = ft_counts(s, c, start);
    ptr = (char *)malloc(total + sizeof(char));
    if (!ptr)
        return (0);
    while (i < total)
    {
        ptr[i] = s[start];
        i++;
        start++;
    }
    ptr[i] = '\0';
    return ptr;
}

char **ft_split(char const *s, char c)
{
    char **arr;
    size_t asize;
    size_t i;

    asize = ft_asize(s, c);
    i = 0;
    arr = (char **)ft_calloc(asize, sizeof(char));
    if (!arr)
        return (0);
    while (i < asize)
    {
        arr[i] = ft_strgen(s, c, i + 1);
        if (!arr[i])
            return (0);
        i++;
    }
    return arr;
}
