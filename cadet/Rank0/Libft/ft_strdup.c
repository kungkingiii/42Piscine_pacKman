/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 10:11:37 by chongsen          #+#    #+#             */
/*   Updated: 2023/08/02 15:11:35 by chongsen         ###   ########.fr       */
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

char *ft_strdup(const char *str)
{
	char *ptr;
	int i;

	ptr = (char *)malloc(ft_strlen(str) * sizeof(char));
	if (!ptr)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

#include <stdio.h>
#include <string.h>

int main()
{
	printf("%s\n", ft_strdup("sad bvb"));
	printf("%s\n", strdup("sad bvb"));
}
