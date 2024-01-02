/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:00:05 by chongsen          #+#    #+#             */
/*   Updated: 2023/10/22 17:01:59 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((((unsigned char *)s1)[i] != ((unsigned char *)s2)[i]))
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++ ;
	}
	return (0);
}
