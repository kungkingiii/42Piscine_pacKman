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

int ft_check_form(const char *str, va_list arg)
{
	if (*str == 'c')
	{
		return (ft_putchar(va_arg(arg, int)));
	}
	else if (*str == 's')
	{
		return (ft_putstr(va_arg(arg, char *)));
	}
	return (0);
}

int ft_printf(const char *str, ...)
{
	int res;
	int count;
	va_list arg;

	count = 0;
	va_start(arg, str);
	// n = va_arg(arg, int);
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
	ft_printf("abcde%shh%c\n", "mytest", 'v');
	printf("ss%svvl%c", "origin", 'v');
}
