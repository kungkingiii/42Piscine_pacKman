/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:13:58 by chongsen          #+#    #+#             */
/*   Updated: 2024/01/03 16:16:59 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	numlen(int n, int base)
{
	int	i;

	i = 0;
	if (n < 10)
		return (1);
	while (n > 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}

static char	*strgen(char *s, int len, int n)
{
	int	i;
	int	r;

	i = len - 1;
	r = n;
	if (n == -2147483648)
		r = 147483648;
	if (n < 0 && n != -2147483648)
		r = n * -1;
	while (i >= 0)
	{
		if (i == 0 && n < 0)
			s[i] = '-';
		else if (i == 1 && n == -2147483648)
			s[i] = '2';
		else if (r >= 10)
		{
			s[i] = r % 10 + '0';
			r = r / 10;
		}
		else
			s[i] = r + '0';
		i--;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	int		len;
	int		t;
	char	*s;

	t = n;
	if (n == -2147483648)
		t = 147483648;
	if (n < 0 && n != -2147483648)
		t = n * -1;
	len = numlen(t, 10);
	if (n == -2147483648)
		len = len + 2;
	if (n < 0 && n != -2147483648)
		len = len + 1;
	s = (char *)malloc((len + 1) * sizeof(char));
	if (!s)
	{
		return (0);
	}
	strgen(s, len, n);
	s[len] = '\0';
	return (s);
}
