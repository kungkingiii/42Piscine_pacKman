/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:37:14 by chongsen          #+#    #+#             */
/*   Updated: 2023/07/18 14:16:35 by chongsen         ###   ########.fr       */
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

int	ft_find_max(int *tab, int size)
{
	int	a;
	int	i;

	i = 0;
	a = i;
	while (i < size - 1)
	{
		if (tab[i + 1] > tab[i] && tab[i + 1] > tab[a])
		{
			a = i + 1;
		}
		i++;
	}
	return (a);
}

void	ft_sort_max(int *tab, int size)
{
	int	h;
	int	a;
	int	*c;
	int	*b;

	a = ft_find_max(tab, size);
	h = a;
	while (h < size)
	{
		if (tab[a] > tab[h])
		{
			c = &tab[a];
			b = &tab[h];
			ft_swap(c, b);
			a = h;
		}
		h++;
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	while (size != 0)
	{
		ft_sort_max(tab, size);
		size = size - 1;
	}
}
