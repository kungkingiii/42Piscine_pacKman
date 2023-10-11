#include<stddef.h>
#include<stdio.h>
int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while(i < n)
	{
		if ((((unsigned char *)s1)[i] != ((unsigned char *)s2)[i]))
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return 0;
}

// int ft_memcmp(const void *s1, const void *s2, size_t n)
// {
// 	size_t	i;

// 	i = 0;
// 	while(i < n)
// 	{
// 		if ((*(unsigned char*)(s1 + i) != *(unsigned char*)(s2 + i)))
// 			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
// 		i++;
// 	}
// 	return 0;
// }

#include<string.h>
int main(void)
{
	char *myarr = "abcgg";
	char *fnarr = "abk";
	char *myint = "abcgg";
	char *fnint = "abk";

	printf("myfn: %d\n", ft_memcmp(myarr, fnarr, 4));
	printf("orgfn: %d\n", memcmp(myint, fnint, 4));
	
}
