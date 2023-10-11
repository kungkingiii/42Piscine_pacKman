/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:33:19 by chongsen          #+#    #+#             */
/*   Updated: 2023/07/26 12:30:00 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
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

size_t ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t l1;
	size_t max;
	size_t is;

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

#include <stdio.h>
#include <string.h>
int main(void)
{
	char str1[40] = "Hello,hi";
	char str2[] = "World! myfriend";
	// char str3[40] = "Hello,hi";
	// char str4[] = "World! myfriend";
	unsigned int size;
	size = 50;
	printf("%d\n", ft_strlcat(str1, str2, size));
	// printf("%d\n", strlcat(str3, str4, size));
	printf("%s\n", str1);
	// printf("%s\n", str3);
}
