int ft_isdigit(char c)
{
	if(c >= 48 && c <= 57)
	{
		return 1;
	}
	return 0;	
}
#include<stdio.h>
#include<ctype.h>
int main(void)
{
	printf("%d\n", ft_isdigit('%'));
	printf("%d\n", ft_isdigit('0'));
	printf("%d\n", ft_isdigit('a'));
	printf("%d\n", isdigit('%'));
	printf("%d\n", isdigit('0'));
	printf("%d", isdigit('a'));
}
