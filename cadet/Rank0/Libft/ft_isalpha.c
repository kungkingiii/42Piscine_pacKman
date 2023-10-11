int ft_isalpha(int c)
{
	if((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return 1;
	}
	return 0;	
}
#include<stdio.h>
#include<ctype.h>
int main(void)
{
	char c = '5';
	char b = 'K';

	printf("%d\n", ft_isalpha(c));
	printf("%d\n", ft_isalpha(b));
	printf("%d\n", isalpha(c));
	printf("%d", isalpha(b));
}
