/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hallykmr <Hallykmr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:55:15 by chongsen          #+#    #+#             */
/*   Updated: 2024/01/02 12:45:45 by Hallykmr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdlib.h>
// #include <stdarg.h>
// #include <unistd.h>
// #include <stdint.h>
// #include <stdio.h>
#include "includes/ft_printf.h"

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

// int main(void)
// {

// 	int x = 88;
// 	int *ptr = &x;
// 	ft_printf("abcdehh%X\n", -200);
// 	printf("ssvv%X\n", -65);
// 	ft_printf("this is my pointer%p\n", (void *)ptr);
// 	printf("this is pointer%p", (void *)ptr);
// }
