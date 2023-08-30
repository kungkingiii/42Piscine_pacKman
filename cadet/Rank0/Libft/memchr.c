#include<stdlib.h>
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

#include<stdio.h>
#include<string.h>
int main(void)
{
	char *mystr = "I want you to fooind ome";
	char *mystr2 = "I want you to fooind ome";
	char schar = '\0';
	char nchar = 'f';

	

	printf("myfn: %ld\n", (const char *)ft_memchr(mystr, schar,24));
	printf("myfn: %ld\n", ft_memchr(mystr, nchar,24));
	printf("originfn: %ld\n", memchr(mystr2, schar, 24));
	printf("originfn: %ld\n", memchr(mystr2, nchar, 24));
	printf("null: %ld", '\0');
}
