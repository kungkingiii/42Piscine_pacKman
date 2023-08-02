/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 08:41:40 by kmahoran          #+#    #+#             */
/*   Updated: 2023/07/24 12:12:00 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int assign_size(void);

int check_a(int a[9][9], char *s);

int check_left(int a[9][9], int x, int n, char *s);

int check_right(int a[9][9], int x, int n, char *s);

void show(int a[9][9]);

void solve(int a[9][9], char *s);

int pos(int a[9][9], int x, int y, int n)
{
	int i;
	int size;

	size = assign_size();
	i = -1;
	while (++i < size)
	{
		if (a[x][i] == n)
			return (0);
	}
	i = -1;
	while (++i < size)
	{
		if (a[i][y] == n)
			return (0);
	}
	return (1);
}

void res(int a[9][9], int x, int y, char *s)
{
	int n;
	int size;

	size = assign_size();
	n = 0;
	while (++n < size + 1)
	{
		if (pos(a, x, y, n))
		{
			a[x][y] = n;
			if (y == size - 1 && check_right(a, x, n, s) == 0)
			{
				a[x][y] = 0;
				return;
			}
			if (y == size - 1 && check_left(a, x, a[x][0], s) == 0)
			{
				a[x][y] = 0;
				return;
			}

			solve(a, s);
			a[x][y] = 0;
		}
	}
	return;
}

void solve(int a[9][9], char *s)
{
	int i[2];
	int size;
	// show(a);
	size = assign_size();
	if (s[(size * 4) - 1] == 0)
	{
		// show(a);
		return;
	}

	i[0] = -1;
	while (++i[0] < size)
	{

		i[1] = -1;
		while (++i[1] < size)
		{
			if (a[i[0]][i[1]] == 0)
			{
				res(a, i[0], i[1], s);
				return;
			}
		}
	}
	if (check_a(a, s))
	{
		show(a);
		s[(size * 4) - 1] = 0;
	}
}
