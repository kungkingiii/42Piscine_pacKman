/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printletter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hallykmr <Hallykmr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 00:17:49 by Hallykmr          #+#    #+#             */
/*   Updated: 2024/01/03 00:21:18 by Hallykmr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar(const char c)
{
	return (write (1, &c, 1));
}

int	ft_putstr(const char *str)
{
	size_t	i;

	if (!str)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	i = 0;
	while (str[i])
	{
		if (write(1, &str[i], 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}
