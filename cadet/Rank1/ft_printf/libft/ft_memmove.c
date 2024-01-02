/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:04:41 by chongsen          #+#    #+#             */
/*   Updated: 2023/10/24 14:05:05 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ndst;
	unsigned char	*nsrc;

	ndst = (unsigned char *)dst;
	nsrc = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if (dst > src)
		while (len-- > 0)
			ndst[len] = nsrc[len];
	else
		ft_memcpy(ndst, nsrc, len);
	return ((char *)dst);
}
