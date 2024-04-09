/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:30:25 by chongsen          #+#    #+#             */
/*   Updated: 2023/10/22 17:30:26 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	l1;
	size_t	max;
	size_t	is;

	l1 = ft_strlen(dest);
	max = size - l1;
	i = 0;
	is = l1 + ft_strlen(src);
	if (size <= l1)
		return (is + max);
	while (i < max - 1 && src[i] != '\0')
	{
		dest[l1] = src[i];
		l1++;
		i++;
	}
	dest[l1] = '\0';
	return (is);
}
