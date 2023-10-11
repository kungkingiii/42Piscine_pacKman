#include<stdlib.h>
void *ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	while(i < len)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return dst;
}

#include<stdio.h>
#include<string.h>
int main(void)
{
	char myarr[5];
	char ccarr[5];
	char fnarr[5] = "abcd";
	char ccsrcarr[5] = "abcd";
	int myint[6];
	int myint2[6];
	int fnint[6] = {1, 2, 3, 4, 5, 6};
	int fnint2[6] = {1, 2, 3, 4, 5, 6};

	ft_memmove(myarr, fnarr, sizeof(myarr));
	memmove(ccarr, ccsrcarr, sizeof(ccarr));
	//ft_memcpy(myint, 'v', sizeof(myint));
	ft_memmove(myint, fnint, sizeof(myint));
	memmove(myint2, fnint2, sizeof(myint2));
	//memcpy(fnarr, 5, sizeof(fnarr));



	printf("myfn: %s\n", myarr);
	printf("orgfn: %s\n", ccarr);
	
	for(int i = 0; i < 6; i++)
	{
		printf("myint: %d\n", myint[i]);
		printf("orgint: %d\n", myint2[i]);

	}
}
