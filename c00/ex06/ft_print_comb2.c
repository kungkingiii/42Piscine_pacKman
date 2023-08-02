/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 10:03:45 by chongsen          #+#    #+#             */
/*   Updated: 2023/07/15 10:09:56 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_output(char f, char s, char t, char o)
{
	write(1, &f, 1);
	write(1, &s, 1);
	write(1, " ", 1);
	write(1, &t, 1);
	write(1, &o, 1);
	if (f != '9' || s != '8' || t != '9' || o != '9')
	{
		write(1, ", ", 2);
	}
}

void	ft_second(int first)
{
	char	a;
	char	b;
	char	c;
	char	d;	

	a = first / 10 + '0';
	b = first % 10 + '0';
	c = b + 1;
	d = a;
	while (d <= '9')
	{
		while (c <= '9')
		{
			ft_output(a, b, d, c);
			c++;
		}
		d++;
	}
}

void	ft_print_comb2(void)
{
	int	a;

	while (a <= 99)
	{
		ft_second(a);
		a++;
	}
}
