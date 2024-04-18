/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:52:25 by bperez-a          #+#    #+#             */
/*   Updated: 2024/04/18 14:22:52 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

static void	fill(char ***map, int i, int j, bool *has_changed)
{
	if ((*map)[i][j - 1] != '1' && (*map)[i][j - 1] != 'P')
	{
		(*map)[i][j - 1] = 'P';
		*has_changed = true;
	}
	if ((*map)[i][j + 1] != '1' && (*map)[i][j + 1] != 'P')
	{
		(*map)[i][j + 1] = 'P';
		*has_changed = true;
	}
	if ((*map)[i + 1][j] != '1' && (*map)[i + 1][j] != 'P')
	{
		(*map)[i + 1][j] = 'P';
		*has_changed = true;
	}
	if ((*map)[i - 1][j] != '1' && (*map)[i - 1][j] != 'P')
	{
		(*map)[i - 1][j] = 'P';
		*has_changed = true;
	}
}

static bool	check_after_fill(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E' || map[i][j] == 'C')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_path(char **map)
{
	bool	has_changed;
	int		i;
	int		j;

	has_changed = true;
	while (has_changed)
	{
		i = 0;
		has_changed = false;
		while (map[i])
		{
			j = 0;
			while (map[i][j])
			{
				if (map[i][j] == 'P')
					fill(&map, i, j, &has_changed);
				j++;
			}
			i++;
		}
	}
	return (check_after_fill(map));
}
