/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:21:12 by chongsen          #+#    #+#             */
/*   Updated: 2023/10/24 16:26:26 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_checknbr(int nb, int fd)
{
	char	b;
	char	i;

	i = nb % 10 + '0';
	b = nb + '0';
	if (nb >= 10)
	{
		ft_checknbr(nb / 10, fd);
		write(fd, &i, 1);
	}
	else
	{
		write(fd, &b, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-", 1);
		write(fd, "2", 1);
		n = 147483648;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	ft_checknbr(n, fd);
}
