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

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	if (str[count] == '\0')
	{
		return (0);
	}
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

void	ft_putstr(char *str1, char *str2)
{
	int	len1;
	int	len2;
	int	i;

	i = 0;
	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	if (len2 != 0)
	{
		while (i < len2)
		{
			str1[len1] = str2[i];
			len1++;
			i++;
		}
	}
}

void	ft_crtstr(char *str, char **strs, int size, char *sep)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putstr(str, strs[i]);
		if (i + 1 != size)
		{
			ft_putstr(str, sep);
		}
		i++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		asize;
	int		allsize;
	char	*str;

	i = 0;
	asize = 0;
	while (i < size)
	{
		asize = asize + ft_strlen(strs[i]);
		i++;
	}
	allsize = asize + ((size - 1) * ft_strlen(sep));
	if (size == 0)
		allsize = 1;
	str = (char *)malloc(allsize * sizeof(char));
	if (!str)
	{
		return (0);
	}
	ft_crtstr(str, strs, size, sep);
	str[allsize] = '\0';
	return (str);
}
/*
int main()
{
	char	*strs[] = {"", "Hello", "", "world"};
	char	*sep = "-";
	char	*arr;
	printf("%s\n", ft_strjoin(4, strs, sep));
	arr = ft_strjoin(4, strs, sep);
	int i = 0;
	while(i < 12)
	{
		if(arr[i] == '\0')
		{
			printf("i: %i gg: %c\n",i, arr[i]);
		}
		printf("i: %i c: %c\n",i, arr[i]);
		i++;
	}
}*/
