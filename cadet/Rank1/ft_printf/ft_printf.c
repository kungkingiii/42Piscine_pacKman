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
	return write (1, &c, 1); 
}

int ft_check_form(const char *str, va_list arg)
{
	if (*str == 'c')
	{
		return(ft_putchar (va_arg(arg, int)));
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		res;
	va_list	arg;

	va_start(arg, str);
	// n = va_arg(arg, int);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			res = ft_check_form(str, arg);
		}
		str++;
	}
	va_end(arg);
	return (res);
}

int	main(void)
{
	ft_printf("abcde%c\n", 'a');
	printf("ss%c", 'g');
}
