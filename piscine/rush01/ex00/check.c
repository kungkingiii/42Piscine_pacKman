/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahoran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 08:59:32 by kmahoran          #+#    #+#             */
/*   Updated: 2023/07/23 13:52:47 by kmahoran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	assign_size(void);

int	check_up(int a[9][9], int y, int n, char *s)
{
	int		i[2];
	int		size;

	size = assign_size();
	i[0] = 0;
	i[1] = 1;
	while (++i[0] < size)
	{
		if (a[i[0]][y] > n)
		{
			n = a[i[0]][y];
			i[1]++;
		}
	}
	if (s[y] == i[1] + 48)
		return (1);
	return (0);
}

int	check_down(int a[9][9], int y, int n, char *s)
{
	int	i[2];
	int	size;

	size = assign_size();
	i[0] = size;
	i[1] = 1;
	while (--i[0] > -1)
	{
		if (a[i[0]][y] > n)
		{
			n = a[i[0]][y];
			i[1]++;
		}
	}
	if (s[y + size] == i[1] + 48)
		return (1);
	return (0);
}

int	check_left(int a[9][9], int x, int n, char *s)
{
	int	i[2];
	int	size;

	size = assign_size();
	i[0] = 0;
	i[1] = 1;
	while (++i[0] < size)
	{
		if (a[x][i[0]] > n)
		{
			n = a[x][i[0]];
			i[1]++;
		}
	}
	if (s[x + (2 * size)] == i[1] + 48)
		return (1);
	return (0);
}

int	check_right(int a[9][9], int x, int n, char *s)
{
	int	i[2];
	int	size;

	size = assign_size();
	i[0] = size;
	i[1] = 1;
	while (--i[0] > -1)
	{
		if (a[x][i[0]] > n)
		{
			n = a[x][i[0]];
			i[1]++;
		}
	}
	if (s[x + (3 * size)] == i[1] + 48)
		return (1);
	return (0);
}

int	check_a(int a[9][9], char *s)
{
	int	i[3];
	int	size;

	size = assign_size();
	i[0] = -1;
	while (++i[0] < size)
	{
		i[1] = -1;
		while (++i[1] < size)
		{
			if (i[0] == 0)
				if (check_up(a, i[1], a[i[0]][i[1]], s) == 0)
					return (0);
			if (i[0] == size - 1)
				if (check_down(a, i[1], a[i[0]][i[1]], s) == 0)
					return (0);
			if (i[1] == 0)
				if (check_left(a, i[0], a[i[0]][i[1]], s) == 0)
					return (0);
			if (i[1] == size - 1)
				if (check_right(a, i[0], a[i[0]][i[1]], s) == 0)
					return (0);
		}
	}
	return (1);
}
