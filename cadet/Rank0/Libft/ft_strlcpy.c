#include <stdlib.h>
#include "libft.h"

size_t ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t srclen;

	i = 0;
	srclen = ft_strlen(src);
	if (size == 0)
		return (srclen);
	while (i < size - 1 && i < srclen)
	{
		dest[i] = *src;
		src++;
		i++;
	}
	dest[i] = '\0';
	return (srclen);
}
