/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:48:44 by bperez-a          #+#    #+#             */
/*   Updated: 2024/04/17 17:10:55 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	d;
	int				i;
	int				len;

	d = (unsigned char)c;
	i = 0;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (s[i] == d)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}
