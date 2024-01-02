/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hallykmr <Hallykmr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 00:33:32 by Hallykmr          #+#    #+#             */
/*   Updated: 2024/01/03 02:13:02 by Hallykmr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_hex(int n)
{
	int				count;
	unsigned int	nbr;

	count = 0;
	nbr = n;
	while (nbr != 0)
	{
		nbr = nbr / 16;
		count++;
	}
	return (count);
}

char	check_hex(int h, char f)
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

char	*dec_to_hex(unsigned int n, char f, int hexlen)
{
	int		i;
	char	*s;

	i = hexlen - 1;
	s = calloc(hexlen + 1, sizeof(char));
	if (!s)
		return (0);
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
	return (s);
}

int	ft_puthex_int(unsigned int n, char f)
{
	int		hexlen;
	char	*hex;
	int		ret;

	ret = 0;
	hexlen = count_hex(n);
	hex = dec_to_hex(n, f, hexlen);
	ft_putstr(hex);
	ret = hexlen;
	free(hex);
	if (n == 0)
		ret += ft_putchar('0');
	return (ret);
}
