int ft_isalnum(char c)
{
	if((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return 1;
	}else if (c >= 48 && c <= 57)
	{
		return 4;
	}	
	return 0;	
}
#include<stdio.h>
#include<ctype.h>
int main(void)
{
	printf("%d\n", ft_isalnum('%'));
	printf("%d\n", ft_isalnum('8'));
	printf("%d\n", ft_isalnum('H'));
	printf("%d\n", isalnum('%'));
	printf("%d\n", isalnum('8'));
	printf("%d", isalnum('H'));
}
