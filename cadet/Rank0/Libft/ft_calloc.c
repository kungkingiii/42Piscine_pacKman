#include <stdlib.h>

void *ft_bzero(void *s, size_t n)
{
    size_t i;

    i = 0;
    while (i < n)
    {
        ((unsigned char *)s)[i] = 0;
        i++;
    }
    return s;
}

void *ft_calloc(size_t count, size_t size)
{
    void *ptr;
    size_t total;

    total = count * size;
    ptr = (void *)malloc(total);
    if (!ptr)
        return (0);
    ft_bzero(ptr, total);
    return (ptr);
}
