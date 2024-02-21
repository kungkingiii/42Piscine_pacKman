/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:35:43 by marvin            #+#    #+#             */
/*   Updated: 2024/02/18 17:35:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>

typedef struct s_da
{
	char *s;
	char *bf;
	char *nl;
	int read_f;
	int error_malloc;
	int error_join;
} t_dat;

char *get_next_line(int fd)
{
	static t_dat data;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
}

int main(void)
{
	int fd;
	char *s;

	fd = open("mytext.txt", O_RDONLY);
	s = get_next_line(fd);
	//	while (s)
	//	{
	// printf("%s", s);
	// free(s);
	//		s = get_next_line(fd);
	//	}
	//	free(s);

	// s = get_next_line(fd);
	// printf("%s", s);
	// free(s);
	return (0);
}