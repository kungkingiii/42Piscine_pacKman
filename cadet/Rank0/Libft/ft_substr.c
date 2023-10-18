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

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t slen;
    size_t i;
    char *ptr;

    slen = ft_strlen(s);
    if ((slen - 1) < start)
        len = 0;
    else if ((slen - start) < len)
        len = slen - start;
    ptr = (char *)malloc(len + 1 * sizeof(char));
    if (!ptr)
        return (0);
    i = 0;
    while (i < len)
    {
        ptr[i] = s[start];
        i++;
        start++;
    }
    ptr[i] = '\0';
    return (ptr);
}
