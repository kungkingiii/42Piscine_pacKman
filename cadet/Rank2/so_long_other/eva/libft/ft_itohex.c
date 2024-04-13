/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperez-a <bperez-a@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 21:39:09 by bperez-a          #+#    #+#             */
/*   Updated: 2024/02/17 23:01:39 by bperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itohex(unsigned long long num, char case_type)
{
	char				*hex;
	char				*base;
	int					len;
	unsigned long long	tmp;

	len = 1;
	tmp = num / 16;
	base = "0123456789abcdef";
	if (case_type == 'X')
		base = "0123456789ABCDEF";
	while (tmp)
	{
		tmp /= 16;
		len++;
	}
	hex = (char *)malloc(sizeof(char) * (len + 1));
	if (!hex)
		return (NULL);
	hex[len] = '\0';
	while (len--)
	{
		hex[len] = base[num % 16];
		num /= 16;
	}
	return (hex);
}
