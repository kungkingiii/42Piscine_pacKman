/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:55:12 by chongsen          #+#    #+#             */
/*   Updated: 2023/08/02 15:14:01 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

size_t ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return i;
}

size_t ft_strcpy(char *dest, const char *src, size_t size)
{
	size_t n;

	n = 0;
	while (src[n] != '\0')
	{
		dest[size] = src[n];
		size++;
		n++;
	}
	return n;
}

char *ft_strjoin(char const *s1, char const *s2)
{
	char *str;
	size_t len;
	size_t i;
	size_t n;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(len * sizeof(char));
	if (!str)
	{
		return (0);
	}
	n = ft_strcpy(str, s1, i);
	ft_strcpy(str, s2, n);
	str[len] = '\0';
	return (str);
}

#include <stdio.h>
int main()
{
	char *strs = "good";
	char *str2 = "morning";
	printf("%s\n", ft_strjoin(strs, str2));

	char *res = ft_strjoin(strs, str2);
	size_t i = 0;
	while (i <= ft_strlen(res))
	{
		if (res[i] == '\0')
		{
			printf("i: %i gg: %c\n", i, res[i]);
		}
		printf("i: %i c: %c\n", i, res[i]);
		i++;
	}
}
