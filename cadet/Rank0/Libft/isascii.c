int ft_isascii(char c)
{
	if ((c >= 0 && c <= 126) || c == 127)
	{
		return 1;
	}
	return 0;	
}
#include<stdio.h>
#include<ctype.h>
int main(void)
{
	printf("%d\n", ft_isascii('%'));
	printf("%d\n", ft_isascii('0'));
	printf("%d\n", ft_isascii('a'));
	printf("%d\n", ft_isascii(127));
	printf("%d\n", ft_isascii(135));
	printf("%d\n", ft_isascii(5));
	printf("isascii: %d\n", isascii('%'));
	printf("%d\n", isascii('0'));
	printf("%d\n", isascii('a'));
	printf("%d\n", isascii(127));
	printf("%d\n", isascii(135));
	printf("%d\n", isascii(5));
}
