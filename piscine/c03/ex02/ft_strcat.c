/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:54:04 by chongsen          #+#    #+#             */
/*   Updated: 2023/07/25 16:12:26 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
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

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	l1;

	l1 = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0')
	{
		dest[l1] = src[i];
		i++;
		l1++;
	}
	dest[l1] = '\0';
	return (dest);
}
/*
int main(void)
{
    char str1[20] = "Hello,";
    char str2[] = "World!";
    printf("%s\n", str1);
    printf("\n-----");
    printf("%s\n", ft_strcat(str1, str2));
}
*/
