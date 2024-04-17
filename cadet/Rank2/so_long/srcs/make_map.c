/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hallykmr <Hallykmr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 09:34:03 by bperez-a          #+#    #+#             */
/*   Updated: 2024/04/17 23:55:13 by Hallykmr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

static void	make_collectible_indexes(t_map **map_data, char **map)
{
	int	i;
	int	collec_pos;
	int	j;

	i = 0;
	collec_pos = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
			{
				(*map_data)->c_x[collec_pos] = j;
				(*map_data)->c_y[collec_pos] = i;
				collec_pos++;
			}
			j++;
		}
		i++;
	}
	(*map_data)->rows = i;
}

static void	make_collectibles(t_map **map_data, char *buffer, char **map)
{
	int	i;
	int	j;

	i = -1;
	(*map_data)->collectibles = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C')
				(*map_data)->collectibles++;
		}
	}
	(*map_data)->c_x = malloc(sizeof(int) * (*map_data)->collectibles);
	(*map_data)->c_y = malloc(sizeof(int) * (*map_data)->collectibles);
	if ((*map_data)->c_x == NULL || (*map_data)->c_y == NULL)
	{
		free((*map_data)->c_x);
		free((*map_data)->c_y);
		free(buffer);
		free(*map_data);
		exit(EXIT_FAILURE);
	}
	make_collectible_indexes(map_data, map);
}

t_map	*make_map(char *buffer)
{
	char	**map;
	t_map	*map_data;

	map_data = malloc(sizeof(t_map));
	if (map_data == NULL)
	{
		free(buffer);
		exit(EXIT_FAILURE);
	}
	map = ft_split(buffer, '\n');
	if (map == NULL)
	{
		free(buffer);
		free(map_data);
		exit(EXIT_FAILURE);
	}
	map_data->map = map;
	map_data->cols = ft_strlen(map[0]);
	map_data->moves = 0;
	make_collectibles(&map_data, buffer, map);
	map_data->collected = 0;
	return (map_data);
}
