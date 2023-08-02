/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 15:35:10 by chongsen          #+#    #+#             */
/*   Updated: 2023/07/15 15:35:13 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_putchar();

void ft_checkdot(int col, int row, int x, int y)
{
	if (((col == 0) && (row == 0)) || ((col == (x - 1)) && (row == (y - 1))))
	{
		if (((x == 1) && (row != 0)) || ((y == 1) && (col != 0)))
			ft_putchar(92);
		else
			ft_putchar('/');
	}
	else if (((col == 0) && (row == (y - 1))) || ((row == 0) && (col == (x - 1))))
		ft_putchar(92);
	else
	{
		if (col == 0 || row == 0 || col == (x - 1) || row == (y - 1))
			ft_putchar('*');
		else
			ft_putchar(' ');
	}
}

void rush(int x, int y)
{
	int col;
	int row;

	col = 0;
	row = 0;
	if (x <= 0 || y <= 0)
		return;
	while (row < y)
	{
		while (col < x)
		{
			ft_checkdot(col, row, x, y);
			col++;
		}
		ft_putchar('\n');
		row++;
		col = 0;
	}
}