/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:15:43 by chongsen          #+#    #+#             */
/*   Updated: 2023/07/25 16:13:16 by chongsen         ###   ########.fr       */
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

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	l1;

	l1 = ft_strlen(dest);
	i = 0;
	while (i < nb && src[i] != '\0')
	{
		dest[l1] = src[i];
		l1++;
		i++;
	}
	dest[l1] = '\0';
	return (dest);
}
/*
int main(void)
{
    char str1[40] = "Hello,hi";
    char str2[] = "World! my friend";
    int i = 0;
    // ft_strcat(str1, str2);

    printf("%s\n", ft_strncat(str1, str2, 20));

    while (i < 40)
    {
        if (str1[i] == '\0')
        {
            printf("%c", 'g');
        }
        else
        {
            printf("%c", str1[i]);
        }
        i++;
    }
}
*/
