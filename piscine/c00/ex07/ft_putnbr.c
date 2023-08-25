/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 13:54:46 by chongsen          #+#    #+#             */
/*   Updated: 2023/07/15 12:02:58 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_checknbr(int nb)
{
	char	b;
	char	i;

	i = nb % 10 + '0';
	b = nb + '0';
	if (nb >= 10)
	{
		ft_checknbr(nb / 10);
		write(1, &i, 1);
	}
	else
	{
		write(1, &b, 1);
	}
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	ft_checknbr(nb);
}
