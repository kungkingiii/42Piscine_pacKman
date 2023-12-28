/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:55:15 by chongsen          #+#    #+#             */
/*   Updated: 2023/10/27 17:35:43 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>
#include <stdio.h>

int ft_putchar(const char c)
{
	return write(1, &c, 1);
}

int ft_putstr(const char *str)
{
	size_t i;

	if (!str)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	i = 0;
	while (str[i])
	{
		if (write(1, &str[i], 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int count_hex(int n)
{
	int count;

	count = 0;
	while (n > 0)
	{
		n = n / 16;
		count++;
	}
	return count;
}

char check_hex(int h, char f)
{
	if (h > 9)
	{
		if (f == 'x')
			return (h - 10 + 'a');
		if (f == 'X')
			return (h - 10 + 'A');
	}
	return (h + '0');
}

char *dec_to_hex(int n, char f, int hexlen)
{
	int i;
	char *s;

	i = hexlen - 1;
	s = (char *)malloc((hexlen) * sizeof(char));
	while (i >= 0)
	{
		if (n > 0)
			s[i] = check_hex(n % 16, f);
		else
			s[i] = check_hex(n / 16, f);
		n = n / 16;
		i--;
	}
	s[hexlen] = '\0';
	return s;
}

int ft_puthex_int(int n, char f)
{
	int hexlen;
	char *hex;

	hexlen = count_hex(n);
	printf("origin%d\n", hexlen);
	hex = dec_to_hex(n, f, hexlen);
	hexlen += ft_putstr(hex);
	free(hex);
	return (hexlen);
}

int ft_ptr_len(uintptr_t num)
{
	int len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void ft_put_ptr(uintptr_t num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar(num + '0');
		else
			ft_putchar(num - 10 + 'A');
	}
}

int ft_putptr(unsigned long long ptr)
{
	int print_length;

	print_length = 0;
	print_length += write(1, "00", 2);
	if (ptr == 0)
		print_length += write(1, "0", 1);
	else
	{
		ft_put_ptr(ptr);
		print_length += ft_ptr_len(ptr);
	}
	return (print_length);
}

int ft_putpercent(void)
{
	write(1, "%", 1);
	return (1);
}

int ft_check_form(const char *str, va_list arg)
{
	if (*str == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (*str == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (*str == 'i' || *str == 'd')
		return (ft_putint(va_arg(arg, int)));
	else if (*str == 'u')
		return (ft_putunsigned_int(va_arg(arg, unsigned int)));
	else if (*str == 'x' || *str == 'X')
		return (ft_puthex_int(va_arg(arg, int), *str));
	else if (*str == 'p')
		return (ft_putptr(va_arg(arg, unsigned long long)));
	else if (*str == '%')
		return (ft_putpercent());
	return (0);
}

int ft_printf(const char *str, ...)
{
	int res;
	int count;
	va_list arg;

	count = 0;
	va_start(arg, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			res = ft_check_form(str, arg);
		}
		else
		{
			ft_putchar(*str);
		}
		str++;
		count += res;
	}
	va_end(arg);
	return (res);
}

int main(void)
{

	int x = 88;
	int *ptr = &x;
	ft_printf("abcdehh%X\n", -200);
	printf("ssvv%X\n", -65);
	ft_printf("this is my pointer%p\n", (void *)ptr);
	printf("this is pointer%p", (void *)ptr);
}
