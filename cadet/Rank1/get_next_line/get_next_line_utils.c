/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:07:06 by kdanchal          #+#    #+#             */
/*   Updated: 2024/01/04 17:08:43 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (s && *s != (char)c)
	{
		if (!(*s))
			return (NULL);
		s++;
	}
	return ((char *)s);
}

char	*ft_strndup(const char *s1, size_t n)
{
	char	*s2;
	size_t	i;

	if (n < 1 || s1 == NULL)
		return (NULL);
	i = 0;
	s2 = malloc(sizeof(char) * (n + 1));
	if (s2 == NULL)
		return (NULL);
	while (s1[i] && i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str || !s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
		str[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

void	gnl6_keep(t_dat *data)
{
	char	*keep;

	data->nl = NULL;
	keep = ft_strchr(data->s, '\n') + 1;
	keep = ft_strndup(keep, ft_strlen(keep));
	free(data->s);
	data->s = keep;
	data->nl = ft_strchr(data->s, '\n');
}
