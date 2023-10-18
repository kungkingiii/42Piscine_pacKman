#include <stdlib.h>
#include "libft.h"

size_t ft_strcpy(char *dest, const char *src, size_t size)
{
	size_t n;

	n = 0;
	while (src[n] != '\0')
	{
		dest[size] = src[n];
		size++;
		n++;
	}
	return n;
}

char *ft_strjoin(char const *s1, char const *s2)
{
	char *str;
	size_t len;
	size_t i;
	size_t n;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(len * sizeof(char));
	if (!str)
	{
		return (0);
	}
	n = ft_strcpy(str, s1, i);
	ft_strcpy(str, s2, n);
	str[len] = '\0';
	return (str);
}
