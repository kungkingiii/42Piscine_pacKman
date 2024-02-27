/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:18:17 by chongsen          #+#    #+#             */
/*   Updated: 2024/02/27 14:25:13 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	ft_counts(char const *s, char c, unsigned int start, int mode)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (s[i] == '\0' && mode == 1)
		return (0);
	while (s[i] != '\0' && mode == 1)
	{
		if (s[i] == c && i != 0 && s[i - 1] != c)
			count++;
		if (s[i + 1] == '\0' && s[i] != c)
			count++;
		i++;
	}
	while (s[start] != '\0' && mode == 2)
	{
		if (s[start] == c)
		{
			return (count);
		}
		start++;
		count++;
	}
	return (count);
}

static size_t	ft_start(char const *s, char c, unsigned int n)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (s[0] != c)
	{
		if (n == 1)
			return (0);
		else
			n = n - 1;
	}
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
		{
			count++;
			if (count == n)
				return (i + 1);
		}
		i++;
	}
	return (0);
}

static char	*ft_strgen(char const *s, char c, size_t n)
{
	size_t	i;
	size_t	start;
	size_t	total;
	char	*ptr;

	i = 0;
	start = ft_start(s, c, n);
	total = ft_counts(s, c, start, 2);
	ptr = (char *)malloc(total + 1 * sizeof(char));
	if (!ptr)
		return (0);
	while (i < total)
	{
		ptr[i] = s[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static void	free_memerror(char **temp)
{
	int	i;

	i = 0;
	while (temp[i])
	{
		free(temp[i]);
		temp[i] = NULL;
		i++;
	}
	free(temp);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	asize;
	size_t	i;

	asize = ft_counts(s, c, 0, 1);
	i = 0;
	arr = (char **)ft_calloc(asize + 1, sizeof(char *));
	if (!arr || !s)
		return (0);
	while (i < asize)
	{
		if (i == 0 && s[i] == '\0' && c != '\0')
			arr[i] = "";
		else
		{
			arr[i] = ft_strgen(s, c, i + 1);
			if (!arr[i])
			{
				free_memerror(arr);
				return (NULL);
			}
		}
		i++;
	}
	return (arr);
}
