/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: packmanich <packmanich@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:55:15 by chongsen          #+#    #+#             */
/*   Updated: 2024/04/03 23:24:53 by packmanich       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpercent(void)
{
	if (write(1, "%", 1) == -1)
		return (-1);
	return (1);
}

int	ft_check_form(const char str, va_list arg)
{
	int	count;

	count = 0;
	if (str == 'c')
		count += ft_putchar(va_arg(arg, int));
	else if (str == 's')
		count += ft_putstr(va_arg(arg, char *));
	else if (str == 'i' || str == 'd')
		count += ft_putint(va_arg(arg, int));
	else if (str == 'u')
		count += ft_putunsigned_int(va_arg(arg, unsigned int));
	else if (str == 'x' || str == 'X')
		count += ft_puthex_int(va_arg(arg, unsigned int), str);
	else if (str == 'p')
		count += ft_putptr(va_arg(arg, unsigned long long));
	else if (str == '%')
		count += ft_putpercent();
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		res;
	int		i;
	int		tmp;
	va_list	arg;

	res = 0;
	i = 0;
	va_start(arg, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			tmp = ft_check_form(str[i], arg);
		}
		else
			tmp = ft_putchar(str[i]);
		if (tmp == -1)
			return (-1);
		res += tmp;
		i++;
	}
	va_end(arg);
	return (res);
}
