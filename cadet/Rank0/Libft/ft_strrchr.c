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
	if (t == 1)
		return a;
	if (c == 0)
		return (char *)&str[i];
	return 0;
}
