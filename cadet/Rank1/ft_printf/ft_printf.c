# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include <stdio.h>

int ft_printf(const char *str, ...)
{
	// int len;
	va_list	arg;

	va_start(arg, str);
	printf("str is %s",str,&arg);
	return(0);
}

int main(void)
{
	ft_printf("abcde","abc");
	printf("ss%s","abc");
}