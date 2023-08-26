char ft_toupper(int c)
{
	if(c >= 97 && c <= 122)
	{
		return c - 32;
	}
	return c;	
}
#include<stdio.h>
#include<ctype.h>
int main(void)
{
	char c = '5';
	char b = 'K';

	printf("%c\n", ft_toupper(c));
	printf("%c\n", ft_toupper(b));
	printf("%c\n", ft_toupper('g'));
	printf("%c\n", ft_toupper('s'));
	printf("isctype:\n%c\n", toupper(c));
	printf("%c\n", toupper(b));
	printf("%c\n", toupper('g'));
	printf("%c", toupper('s'));
}
