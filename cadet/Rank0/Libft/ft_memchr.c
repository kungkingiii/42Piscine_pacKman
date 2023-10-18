#include <stdlib.h>

void *ft_memchr(const void *s, int c, size_t n)
{
	unsigned int i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == c)
		{
			return ((void *)(s + i));
		}
		i++;
	}
	return 0;
}
