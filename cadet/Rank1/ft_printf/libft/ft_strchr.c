/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:26:27 by chongsen          #+#    #+#             */
/*   Updated: 2023/10/24 14:45:05 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	if (c == '\0')
	{
		while (*str != '\0')
			str++;
		return ((char *)str);
	}
	while (*str != (char)c)
	{
		if (*str == '\0')
			return (0);
		str++;
	}
	return ((char *)str);
}
