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

char *ft_strdup(const char *str)
{
	char *ptr;
	int i;

	ptr = (char *)malloc(ft_strlen(str) * sizeof(char));
	if (!ptr)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
