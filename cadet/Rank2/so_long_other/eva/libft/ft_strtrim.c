/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperez-a <bperez-a@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:49:06 by bperez-a          #+#    #+#             */
/*   Updated: 2024/02/09 23:05:16 by bperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isinset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	int		start;
	int		end;
	int		len;

	start = 0;
	while (s1[start] && ft_isinset(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	while (end > start && ft_isinset(s1[end], set))
		end--;
	len = end - start + 1;
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s1 + start, len + 1);
	new[len] = '\0';
	return (new);
}
