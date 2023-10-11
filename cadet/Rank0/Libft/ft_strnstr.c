/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:15:43 by chongsen          #+#    #+#             */
/*   Updated: 2023/07/25 14:01:25 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
int ft_check(char *str, char *to_find, size_t si, size_t ti)
{
	while (to_find[ti] != '\0')
	{
		if (str[si] == to_find[ti])
		{
			ti++;
			si++;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}

char *ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t si;
	size_t r;
	char *need = (char *)little;
	char *find = (char *)big;

	r = 0;
	si = 0;
	if (need[0] == '\0')
	{
		return (&find[si]);
	}
	while (si < len && find[si] != '\0')
	{
		if (find[si] == need[0])
		{
			r = ft_check(find, need, si, 0);
			if (r == 1)
				return (&find[si]);
		}
		si++;
	}
	return (0);
}

#include <stdio.h>
#include <string.h>
int main()
{
	const char *haystack = "This is a sample string for testing.";
	const char *needle = "sample";

	char *result = ft_strnstr(haystack, needle, 15);

	if (result != NULL)
	{
		printf("Found substring: %s\n", result);
	}
	else
	{
		printf("Substring not found.\n");
	}

	return 0;
}