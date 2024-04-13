/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperez-a <bperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:23:05 by bperez-a          #+#    #+#             */
/*   Updated: 2024/03/14 09:58:18 by bperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	handle_char(va_list args)
{
	ft_putchar_fd((char)va_arg(args, int), 1);
	return (1);
}

int	handle_string(va_list args)
{
	char	*string;

	string = va_arg(args, char *);
	if (string == NULL)
		string = "(null)";
	ft_putstr_fd(string, 1);
	return (ft_strlen(string));
}

int	handle_int(va_list args, char type)
{
	char	*string;
	int		len;

	if (type == 'u')
		string = ft_utoa(va_arg(args, unsigned int));
	else
		string = ft_itoa(va_arg(args, int));
	if (!string)
		return (0);
	ft_putstr_fd(string, 1);
	len = ft_strlen(string);
	free(string);
	return (len);
}

int	handle_hex(va_list args, char case_type)
{
	char	*string;
	int		len;

	string = ft_itohex(va_arg(args, unsigned int), case_type);
	if (!string)
		return (0);
	ft_putstr_fd(string, 1);
	len = ft_strlen(string);
	free(string);
	return (len);
}

int	handle_pointer(va_list args)
{
	char	*string;
	int		len;
	void	*ptr;

	ptr = va_arg(args, void *);
	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	string = ft_itohex((unsigned long long)ptr, 'x');
	if (!string)
		return (0);
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(string, 1);
	len = 2 + ft_strlen(string);
	free(string);
	return (len);
}
