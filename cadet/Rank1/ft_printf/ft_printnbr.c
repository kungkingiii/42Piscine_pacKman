/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hallykmr <Hallykmr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 23:47:52 by Hallykmr          #+#    #+#             */
/*   Updated: 2024/01/03 00:28:49 by Hallykmr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"

int	ft_putint(int n)
{
	int		len;
	char	*num;
	int		tmp;

	len = 0;
	num = ft_itoa(n);
	tmp = ft_putstr(num);
	if (tmp == -1)
		return (-1);
	len = tmp;
	free(num);
	return (len);
}

int	ft_num_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_num_len(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (num);
}

int	ft_putunsigned_int(unsigned int n)
{
	int		plen;
	char	*num;

	plen = 0;
	if (n == 0)
		plen += write(1, "0", 1);
	else
	{
		num = ft_uitoa(n);
		plen += ft_putstr(num);
		free(num);
	}
	return (plen);
}
