#include<stdlib.h>
void *ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while(i < len)
	{
		((unsigned char *)b)[i] = c;
		i++;
	}
	return b;
}

#include<stdio.h>
#include<string.h>
int main(void)
{
	char myarr[5];
	char fnarr[5];
	int myint[6];
	int fnint[6];

	ft_memset(myarr, 'v', sizeof(myarr));
	ft_memset(myint, 'v', sizeof(myint));
	memset(fnint, 5, sizeof(fnint));
	memset(fnarr, 5, sizeof(fnarr));



	printf("myfn: %s\n", myarr);
	printf("orgfn: %s\n", myarr);
	
	for(int i = 0; i < 5; i++)
	{
		printf("myint: %d\n", myint[i]);
		printf("orgint: %d\n", fnint[i]);

	}
}
