/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:35:50 by chongsen          #+#    #+#             */
/*   Updated: 2023/07/18 11:27:51 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	s;
	int	n;
	int	*a;
	int	*b;

	i = 0;
	s = size - 1;
	n = size / 2;
	while (i < n)
	{
		a = &tab[i];
		b = &tab[s - i];
		ft_swap(a, b);
		i++;
	}
}
