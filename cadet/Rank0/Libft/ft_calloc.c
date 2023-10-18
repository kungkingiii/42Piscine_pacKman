#include <stdlib.h>
#include <libft.h>

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
