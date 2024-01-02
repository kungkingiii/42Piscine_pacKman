/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:58:23 by chongsen          #+#    #+#             */
/*   Updated: 2023/10/24 14:54:32 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	size_t	i;
	char	*ptr;

	slen = ft_strlen(s);
	if (start > slen)
		return (ft_strdup(""));
	if ((slen - 1) < start)
		len = 0;
	else if ((slen - start) < len)
		len = slen - start;
	ptr = (char *)malloc(len + 1 * sizeof(char));
	if (!ptr)
		return (0);
	i = 0;
	while (i < len)
	{
		ptr[i] = s[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}
