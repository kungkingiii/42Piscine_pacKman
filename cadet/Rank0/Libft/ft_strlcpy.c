/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:01:38 by chongsen          #+#    #+#             */
/*   Updated: 2023/07/25 11:34:35 by chongsen         ###   ########.fr       */
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

size_t ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t srclen;

	i = 0;
	srclen = ft_strlen(src);
	if (size == 0)
		return (srclen);
	while (i < size - 1 && i < srclen)
	{
		dest[i] = *src;
		src++;
		i++;
	}
	dest[i] = '\0';
	return (srclen);
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
	size = 30;
	// unsigned int size2;
	// size2 = 6;
	// size_t copied = strlcpy(str3, str4, size2);
	printf("%d\n", ft_strlcpy(str1, str2, size));
	// printf("%d\n", copied);
	printf("%s\n", str1);
	// printf("%s\n", str3);
}