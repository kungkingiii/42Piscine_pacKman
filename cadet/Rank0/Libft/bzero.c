#include<stdlib.h>
void *ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while(i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
	return s;
}

#include<stdio.h>
#include<unistd.h>
#include<strings.h>
int main(void)
{
	char myarr[5];
	//char fnarr[5];
	int myint[6];
	//int fnint[6];

	write(1,"gg",2);
	ft_bzero(myarr, 3);
	ft_bzero(myint , sizeof(myint));
	//bzero(fnint, sizeof(fnint));
	//bzero(fnarr, sizeof(fnarr));



	printf("myfn: %s\n", myarr);
	printf("orgfn: %s\n", myarr);
	
	for(int i = 0; i < 5; i++)
	{
		printf("myint: %d\n", myint[i]);
		printf("orgint: %d\n", myarr[i]);

	}
}
