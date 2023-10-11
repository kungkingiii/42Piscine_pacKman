char ft_tolower(int c)
{
	if(c >= 65 && c <= 90)
	{
		return c + 32;
	}
	return c;	
}
#include<stdio.h>
#include<ctype.h>
int main(void)
{
	char c = '5';
	char b = 'K';

	printf("%c\n", ft_tolower(c));
	printf("%c\n", ft_tolower(b));
	printf("my: %c\n", ft_tolower('G'));
	printf("my: %c\n", ft_tolower('R'));
	printf("isctype:\n%c\n", tolower(c));
	printf("%c\n", tolower(b));
	printf("ori: %c\n", tolower('G'));
	printf("ori: %c", tolower('R'));
}
