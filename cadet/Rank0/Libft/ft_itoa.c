
#include <stdio.h>
#include <stdlib.h>

int numlen(int n, int base)
{
	int i;

	i = 0;
	if (n < 10)
		return 1;
	while (n > 0)
	{
		n = n / base;
		i++;
	}
	return i;
}

char *strgen(char *s, int len, int n)
{
	int i;
	int r;

	i = len - 1;
	r = n;
	if (n < 0)
		r = n * -1;
	while (i >= 0)
	{
		if (i == 0 && n < 0)
		{
			s[i] = '-';
		}
		else if (r > 10)
		{
			s[i] = r % 10 + '0';
			r = r / 10;
		}
		else
			s[i] = r + '0';
		i--;
	}
	s[len] = '\0';
	return s;
}

char *ft_itoa(int n)
{
	int len;
	int t;
	char *s;

	t = n;
	if (n < 0)
		t = n * -1;
	len = numlen(t, 10);
	if (n < 0)
		len = len + 1;
	s = (char *)malloc((len + 1) * sizeof(char));
	if (!s)
		return (0);
	strgen(s, len, n);
	return s;
}

int main(void)
{
	printf("string: %s\n", ft_itoa(  	-4000));
}
