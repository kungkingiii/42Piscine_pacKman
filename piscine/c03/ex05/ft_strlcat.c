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

unsigned int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	l1;
	unsigned int	n;
	unsigned int	max;
	unsigned int	is;

	l1 = ft_strlen(dest);
	n = l1;
	max = size - l1;
	i = 0;
	is = l1 + ft_strlen(src);
	if (size <= l1)
	{
		return (is + max);
	}
	while (i < max - 1 && src[i] != '\0')
	{
		dest[l1] = src[i];
		l1++;
		i++;
	}
	dest[l1] = '\0';
	return (is);
}
/*
int main(void)
{
	char str1[40] = "Hello,hi";
	char str2[] = "World! myfriend";
	char str3[40] = "Hello,hi";
	char str4[] = "World! myfriend";
	unsigned int size;
	size = 2;
	int i = 0;
	printf("%d\n", ft_strlcat(str1, str2, size));
	printf("%lu\n", strlcat(str3, str4, size));
	printf("%s\n", str1);
	printf("%s\n", str3);
}
*/
