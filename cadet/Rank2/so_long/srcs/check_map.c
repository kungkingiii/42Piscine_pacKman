/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:05:41 by chongsen          #+#    #+#             */
/*   Updated: 2024/04/17 17:06:28 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

bool	check_walls(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (i == 0 || j == 0 || !map[i + 1] || !map[i][j + 1])
				if (map[i][j] != '1')
					return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_inv_sym(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'C'
				&& map[i][j] != 'E' && map[i][j] != 'P')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_sym_count(char **map)
{
	int	c;
	int	e;
	int	p;
	int	i;
	int	j;

	c = 0;
	e = 0;
	p = 0;
	i = -1;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				c++;
			else if (map[i][j] == 'E')
				e++;
			else if (map[i][j] == 'P')
				p++;
			j++;
		}
	}
	return (!(c < 1 || e != 1 || p != 1));
}

bool	check_rectangular(char **map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_strlen(map[0]);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j != len)
			return (false);
		i++;
	}
	return (true);
}

bool	check_map(char **map)
{
	return (check_rectangular(map) && check_sym_count(map) && check_inv_sym(map)
		&& check_walls(map) && check_path(map));
}
