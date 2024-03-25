/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperez-a <bperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 08:05:08 by bperez-a          #+#    #+#             */
/*   Updated: 2024/03/14 09:58:11 by bperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	handle_spec(const char spec, va_list args)
{
	int	print_len;

	if (spec == '%')
	{
		ft_putchar_fd(spec, 1);
		print_len = 1;
	}
	else if (spec == 's')
		print_len = handle_string(args);
	else if (spec == 'c')
		print_len = handle_char(args);
	else if (spec == 'i' || spec == 'd')
		print_len = handle_int(args, 'i');
	else if (spec == 'u')
		print_len = handle_int(args, 'u');
	else if (spec == 'x' || spec == 'X')
		print_len = handle_hex(args, spec);
	else if (spec == 'p')
		print_len = handle_pointer(args);
	else
		return (0);
	return (print_len);
}

int	print_all(const char *str, va_list args)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			count += handle_spec(*str, args);
		}
		else
		{
			ft_putchar_fd(*str, 1);
			count += 1;
		}
		str++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			count;
	const char	*str;

	str = format;
	va_start(args, format);
	count = print_all(str, args);
	va_end(args);
	return (count);
}
