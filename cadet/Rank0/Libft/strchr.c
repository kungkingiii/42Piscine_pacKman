char *ft_strchr(const char *str, int c)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (char *)&str[i];
		i++;
	}
	if(c == 0)
	{
		return (char *)&str[i];
	}
	return 0;
}

#include<stdio.h>
#include<string.h>
int main(void)
{
	char *mystr = "I want you to find me";
	char schar = '\0';

	printf("myfn: %ld\n", ft_strchr(mystr,schar) - mystr);
	printf("originfn: %ld\n", strchr(mystr,schar)- mystr);
}
