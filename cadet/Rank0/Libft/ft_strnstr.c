#include <stdlib.h>

int ft_check(char *str, char *to_find, size_t si, size_t ti)
{
	while (to_find[ti] != '\0')
	{
		if (str[si] == to_find[ti])
		{
			ti++;
			si++;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}

char *ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t si;
	size_t r;
	char *need = (char *)little;
	char *find = (char *)big;

	r = 0;
	si = 0;
	if (need[0] == '\0')
	{
		return (&find[si]);
	}
	while (si < len && find[si] != '\0')
	{
		if (find[si] == need[0])
		{
			r = ft_check(find, need, si, 0);
			if (r == 1)
				return (&find[si]);
		}
		si++;
	}
	return (0);
}
