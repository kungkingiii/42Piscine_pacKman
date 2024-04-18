/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:48:40 by bperez-a          #+#    #+#             */
/*   Updated: 2024/04/18 13:14:12 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static void	free_arr(char **arr, int i)
{
	while (i--)
		free(arr[i]);
	free(arr);
}

static void	write_word(char *dest, char const *src, int n)
{
	int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

static int	allocate_str(char **arr, int index, int len)
{
	if (arr == NULL)
		return (0);
	arr[index] = (char *)malloc(sizeof(char) * (len + 1));
	if (arr[index] == NULL)
	{
		free_arr(arr, index);
		return (0);
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		i;
	int		j;
	int		strs_i;

	strs = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	i = 0;
	strs_i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
			continue ;
		}
		j = 0;
		while (s[i + j] && s[i + j] != c)
			j++;
		if (!allocate_str(strs, strs_i, j))
			return (NULL);
		write_word(strs[strs_i++], s + i, j);
		i += j;
	}
	strs[strs_i] = NULL;
	return (strs);
}
