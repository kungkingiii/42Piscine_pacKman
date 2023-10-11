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

#include <stdio.h>
int main()
{
    int num_elements = 5;
    int *arr;
    int *arr2;

    arr = (int *)ft_calloc(num_elements, sizeof(int));
    arr2 = (int *)calloc(num_elements, sizeof(int));

    if (arr == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    for (int i = 0; i < num_elements; i++)
    {
        arr[i] = i * 10;
        arr2[i] = i * 10;
    }

    for (int i = 0; i < num_elements; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
        printf("arr2[%d] = %d\n", i, arr2[i]);
    }
}
