int ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		if (c >= 48 && c <= 57)
			return 4;
		else if (c >= 65 && c <= 90)
			return 1;
		else if (c >= 97 && c <= 122)
			return 2;
		else
			return 16;
	}
	return 0;
}
