/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:54:58 by chongsen          #+#    #+#             */
/*   Updated: 2023/10/23 00:10:17 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	unsigned int	i;
	char			*a;

	i = 0;
	a = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
		{
			a = (char *)&str[i];
		}
		i++;
	}
	if ((char)c == str[i])
		return ((char *)&str[i]);
	return (a);
}
