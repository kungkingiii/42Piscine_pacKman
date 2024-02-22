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
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUFFER_SIZE 3

typedef struct s_da
{
	char *s;
	char *bf;
	char *nl;
	int read_f;
	int error_malloc;
	int error_join;
} t_dat;

size_t ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char *check_next_line(char *text, int bytes, int fd)
{

	int i;
	char *line_text;

	bytes = read(fd, text, BUFFER_SIZE);
	line_text = (char *)malloc(sizeof(char) * ft_strlen(text));

	i = 0;
	while (text[i])
	{
		if (text[i] == '\n')
		{
			line_text[i] == '\0';
			return (line_text);
		}
		line_text[i] = text[i];
		i++;
	}
	printf("ggg%s, ddd%s\n", text, line_text);
	bytes = read(fd, text, BUFFER_SIZE);

	return (line_text);
}

char *get_next_line(int fd)
{
	// static t_dat data;
	static char *text;
	int bytes;
	// static char buffer[5];
	// ssize_t bytes_read = read(fd, buffer, BUFFER_SIZE);
	// if (bytes_read == -1)
	// {
	// 	perror("read");
	// 	close(fd);
	// 	return buffer;
	// }

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	text = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));

	check_next_line(text, bytes, fd);

	return text;
}

int main(void)
{
	int fd;
	char *s;

	fd = open("mytext.txt", O_RDONLY);
	s = get_next_line(fd);
	printf("%s\n", s);
	s = get_next_line(fd);
	printf("%s\n", s);
	s = get_next_line(fd);
	printf("%s\n", s);
	s = get_next_line(fd);
	printf("%s\n", s);
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