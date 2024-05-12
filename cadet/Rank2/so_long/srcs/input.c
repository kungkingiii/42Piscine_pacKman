/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperez-a <bperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:38:31 by bperez-a          #+#    #+#             */
/*   Updated: 2024/03/18 10:31:05 by bperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

static void	check_validity(char *buffer)
{
	char	**map;
	int		map_len;

	map = ft_split(buffer, '\n');
	if (map == NULL)
	{
		free(buffer);
		exit(EXIT_FAILURE);
	}
	map_len = ft_c_arr_len(map);
	if (map_len == 0 || !check_map(map))
	{
		ft_printf("Error: invalid map\n");
		free(buffer);
		while (map_len--)
			free(map[map_len]);
		free(map);
		exit(EXIT_FAILURE);
	}
	while (map_len--)
		free(map[map_len]);
	free(map);
}

t_map	*handle_input(char *filepath)
{
	char	*buffer;
	t_map	*map_data;
	int		fd;
	int		read_bytes;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error: invalid file\n");
		exit(EXIT_FAILURE);
	}
	buffer = malloc(100000);
	if (buffer == NULL)
		exit(EXIT_FAILURE);
	read_bytes = read(fd, buffer, 100000);
	buffer[read_bytes] = '\0';
	check_validity(buffer);
	map_data = make_map(buffer);
	free(buffer);
	close(fd);
	return (map_data);
}
