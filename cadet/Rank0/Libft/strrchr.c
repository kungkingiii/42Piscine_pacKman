char *ft_strrchr(const char *str, int c)
{
	int i;
	char *a;
	int t;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			t = 1;
			a = (char *)&str[i];
		}
		i++;
	}
	if(t == 1)
		return a;
	if(c == 0)
		return (char *)&str[i];
	return 0;
}

#include<stdio.h>
#include<string.h>
int main(void)
{
	char *mystr = "I want you to fooind ome";
	char *mystr2 = "I want you to fooind ome";
	char schar = '\0';
	char nchar = 'j';

	printf("myfn: %ld\n", ft_strrchr(mystr,schar));
	printf("myfn: %ld\n", ft_strrchr(mystr,nchar));
	printf("originfn: %ld\n", strrchr(mystr2,schar));
	printf("originfn: %ld\n", strrchr(mystr2,nchar));
	printf("null: %ld", '\0');
}
