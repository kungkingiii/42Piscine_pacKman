int ft_isprint(char c)
{
	if(c >= 32 && c <= 126)
	{
		if(c >= 48 && c <= 57)
			return 4;
		else if(c >= 65 && c <= 90) 
			return 1;
		else if(c >= 97 && c <= 122)
			return 2;
		else
			return 16;
	}
	return 0;	
}
#include<stdio.h>
#include<ctype.h>
int main(void)
{
	printf("%d\n", ft_isprint('%'));
	printf("%d\n", ft_isprint('0'));
	printf("%d\n", ft_isprint(50));
	printf("%d\n", ft_isprint('A'));
	printf("%d\n", ft_isprint('L'));
	printf("%d\n", ft_isprint('f'));
	printf("%d\n", ft_isprint('g'));
	printf("%d\n", ft_isprint(30));
	printf("%d\n", ft_isprint(130));
	printf("isprint: \n%d\n", isprint('%'));
	printf("%d\n", isprint('0'));
	printf("%d\n", isprint(50));
	printf("%d\n", isprint('A'));
	printf("%d\n", isprint('L'));
	printf("%d\n", isprint('f'));
	printf("%d\n", isprint('g'));
	printf("%d\n", isprint(30));
	printf("%d\n", isprint(130));
}
