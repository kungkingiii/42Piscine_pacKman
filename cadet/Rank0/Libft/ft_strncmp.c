#include<stdlib.h>
int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (str1[i] != '\0' && str2[i] == '\0' && n != 0)
	{
		return (str1[i] - 0);
	}
	while (i < n && (str2[i] != '\0' || str1[i] != '\0'))
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

#include<stdio.h>
#include<string.h>
int main(void)
{
	char *mystr = "I want yoz";
	char *mystr2 = "I want you to fooind ome";

	printf("myfn: %d\n", ft_strncmp(mystr, mystr2, 5));
	printf("myfn: %d\n", ft_strncmp(mystr, mystr2, 10));
	printf("originfn: %d\n", strncmp(mystr, mystr2, 5));
	printf("originfn: %d\n", strncmp(mystr, mystr2, 10));
}
