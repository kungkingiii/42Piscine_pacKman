#include <stdlib.h>
#include "libft.h"

size_t ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t l1;
	size_t max;
	size_t is;

	l1 = ft_strlen(dest);
	max = size - l1;
	i = 0;
	is = l1 + ft_strlen(src);
	if (size <= l1)
		return (is + max);
	while (i < max - 1 && src[i] != '\0')
	{
		dest[l1] = src[i];
		l1++;
		i++;
	}
	dest[l1] = '\0';
	return (is);
}
