/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: packmanich <packmanich@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 01:03:28 by packmanich        #+#    #+#             */
/*   Updated: 2024/05/28 01:13:12 by packmanich       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	make_collectible_indexes(t_data **data, char **map)
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
				(*data)->c_x[collec_pos] = j;
				(*data)->c_y[collec_pos] = i;
				collec_pos++;
			}
			j++;
		}
		i++;
	}
	(*data)->rows = i;
}

static void	make_collectibles(t_data **data, char *buffer, char **map)
{
	int	i;
	int	j;

	i = -1;
	(*data)->collectibles = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C')
				(*data)->collectibles++;
		}
	}
	(*data)->c_x = malloc(sizeof(int) * (*data)->collectibles);
	(*data)->c_y = malloc(sizeof(int) * (*data)->collectibles);
	if ((*data)->c_x == NULL || (*data)->c_y == NULL)
	{
		free((*data)->c_x);
		free((*data)->c_y);
		free(buffer);
		free(*data);
		exit(1);
	}
	make_collectible_indexes(data, map);
}

t_data	*make_map(char *buffer)
{
	char	**map;
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (data == NULL)
	{
		free(buffer);
		free(data);
		exit(1);
	}
	map = ft_split(buffer, '\n');
	if (map == NULL)
	{
		free(buffer);
		free(data);
		exit(1);
	}
	data->map = map;
	data->cols = ft_strlen(map[0]);
	data->moves = 0;
	make_collectibles(&data, buffer, map);
	data->collected = 0;
	return (data);
}

static void	check_validity(char *buffer)
{
	char	**map;
	int		map_len;

	map = ft_split(buffer, '\n');
	if (map == NULL)
	{
		free(buffer);
		exit(1);
	}
	map_len = ft_c_arr_len(map);
	if (map_len == 0 || !check_map(map))
	{
		ft_printf("Error: invalid map\n");
		free(buffer);
		while (map_len--)
			free(map[map_len]);
		free(map);
		exit(1);
	}
	while (map_len--)
		free(map[map_len]);
	free(map);
}

t_data	*handle_input(char *filepath)
{
	char	*buffer;
	t_data	*data;
	int		fd;
	int		read_bytes;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error: invalid file\n");
		exit(1);
	}
	buffer = malloc(100000);
	if (buffer == NULL)
		exit(1);
	read_bytes = read(fd, buffer, 100000);
	buffer[read_bytes] = '\0';
	check_validity(buffer);
	data = make_map(buffer);
	free(buffer);
	close(fd);
	return (data);
}
