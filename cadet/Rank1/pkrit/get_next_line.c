/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hallykmr <Hallykmr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:07:06 by kdanchal          #+#    #+#             */
/*   Updated: 2024/02/26 23:32:17 by Hallykmr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// #include "get_next_line_utils.c"

char *gnl5_result2(t_dat *data)
{
	char *res;

	res = ft_strndup(data->s, data->nl - data->s + 1);
	if (!res)
	{
		free(data->s);
		data->s = NULL;
		return (NULL);
	}
	if (!(data->nl + 1))
	{
		data->nl = NULL;
		free(data->s);
		data->s = NULL;
		return (res);
	}
	else
	{
		gnl6_keep(data);
		return (res);
	}
}

char *gnl4_result1(t_dat *data)
{
	char *res;

	if (ft_strlen(data->s) == 0 || data->read_f < 0 || data->error_malloc)
	{
		free(data->s);
		data->s = NULL;
		data->nl = NULL;
		data->error_malloc = 0;
		return (NULL);
	}
	if (!data->nl)
	{
		res = ft_strndup(data->s, ft_strlen(data->s));
		free(data->s);
		data->s = NULL;
		return (res);
	}
	else
	{
		res = gnl5_result2(data);
		return (res);
	}
}

char *gnl3_join(t_dat *data)
{
	char *s_new;

	if (data->error_join > 100)
	{
		free(data->s);
		data->s = NULL;
		free(data->bf);
		data->bf = NULL;
		return (NULL);
	}
	s_new = ft_strjoin(data->s, data->bf);
	if (!s_new)
	{
		data->error_malloc = 1;
		data->error_join = data->error_join + 1;
	}
	free(data->s);
	data->s = s_new;
	data->nl = ft_strchr(data->s, '\n');
	return ("abc");
}

char *gnl2_read_dup(t_dat *data, int fd)
{
	while (!data->nl && !data->error_malloc)
	{
		data->read_f = read(fd, data->bf, BUFFER_SIZE);
		if (data->read_f < 1)
			break;
		data->bf[data->read_f] = '\0';
		if (!data->s)
		{
			data->s = ft_strndup(data->bf, data->read_f);
			if (!data->s)
				data->error_malloc = 1;
			data->nl = ft_strchr(data->s, '\n');
		}
		else
		{
			if (!gnl3_join(data))
				return (NULL);
		}
	}
	return ("abc");
}

char *get_next_line(int fd)
{
	static t_dat data;
	char *res;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	data.bf = (char *)malloc(BUFFER_SIZE + 1);
	if (!data.bf)
		data.error_malloc = 1;
	if (!data.nl && !data.error_malloc)
	{
		if (!gnl2_read_dup(&data, fd))
			return (NULL);
	}
	free(data.bf);
	res = gnl4_result1(&data);
	return (res);
}

// #include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

// int main(void)
// {
// 	int fd;
// 	char *s;

// 	fd = open("test.txt", O_RDONLY);
// 	// s = get_next_line(fd);
// 	s = "gg";
// 	while (s)
// 	{
// 		printf("%s", s);
// 		free(s);
// 		s = get_next_line(fd);
// 	}
// 	free(s);

// 	// s = get_next_line(fd);
// 	// printf("%s", s);
// 	// free(s);
// 	// s = get_next_line(fd);
// 	// printf("%s", s);
// 	// free(s);
// 	return (0);
// }