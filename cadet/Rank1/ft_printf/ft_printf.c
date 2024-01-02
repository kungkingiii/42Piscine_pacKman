/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hallykmr <Hallykmr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:55:15 by chongsen          #+#    #+#             */
/*   Updated: 2024/01/03 00:29:54 by Hallykmr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpercent(void)
{
	return (write(1, "%", 1));
}

int	ft_check_form(const char *str, va_list arg)
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
		return (ft_puthex_int(va_arg(arg, unsigned int), *str));
	else if (*str == 'p')
		return (ft_putptr(va_arg(arg, unsigned long long)));
	else if (*str == '%')
		return (ft_putpercent());
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		res;
	int		i;
	va_list	arg;

	if (!str)
		return (0);
	res = 0;
	i = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			res += ft_check_form(&str[i], arg);
		}
		else
		{
			res += ft_putchar(str[i]);
		}
		i++;
	}
	va_end(arg);
	return (res);
}
