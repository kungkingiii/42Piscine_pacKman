/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:42:08 by chongsen          #+#    #+#             */
/*   Updated: 2023/10/24 16:27:02 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_check(char *str, char *to_find, size_t si, size_t len)
{
	size_t	i;

	i = 0;
	while (to_find[i] != '\0')
	{
		if (str[si] == to_find[i])
		{
			i++;
			si++;
		}
		else
		{
			return (0);
		}
	}
	if (si > len)
		return (0);
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	si;
	size_t	r;
	char	*need;
	char	*find;

	if (!haystack && !len)
		return (NULL);
	need = (char *)needle;
	find = (char *)haystack;
	r = 0;
	si = 0;
	if (need[0] == '\0')
		return (&find[si]);
	while (si < len && find[si] != '\0')
	{
		if (find[si] == need[0])
		{
			r = ft_check(find, need, si, len);
			if (r == 1)
				return (&find[si]);
		}
		si++;
	}
	return (0);
}
