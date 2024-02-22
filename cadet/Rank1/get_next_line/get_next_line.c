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

// char *read_line(char *text, int bytes, int fd)
// {
// 	bytes = read(fd, text, BUFFER_SIZE);
// }

void ft_strcat(char *dest, const char *src)
{
	printf("ggg%sdfs%s\n", dest, src);
	size_t i;
	size_t l1;
	size_t max;

	l1 = ft_strlen(dest);
	max = ft_strlen(src);

	i = 0;
	while (src[i] != '\0')
	{
		dest[l1] = src[i];
		l1++;
		i++;
	}
	dest[l1] = '\0';
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
		printf("stringgg cc:%c rr%c\n", line_text[i], text[i]);
		if (text[i] == '\n')
		{
			printf("stringgg :%c\n", text[i]);
			line_text[i] == '\0';
			printf("stringgg ee:%s\n", line_text);
			return (line_text);
		}
		line_text[i] = text[i];
		printf("stringgg aa:%s gg%c\n", line_text, text[i]);
		i++;
	}
	// printf("stringgg aa:%c\n", line_text, text[i]);
	return (line_text);
}

char *get_next_line(int fd)
{
	// static t_dat data;
	static char *text;
	char *read_text;
	char *result;
	int bytes;
	int len;
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

	read_text = check_next_line(text, bytes, fd);

	len = ft_strlen(read_text);

	// ft_strcat(result, read_text);

	// read_text = check_next_line(text, bytes, fd);
	result = read_text;
	printf("result jaa :%s\n", result);

	if (read_text[len] != '\n')
	{
		read_text = check_next_line(text, bytes, fd);
		printf("read_text jaa :%s\n", read_text);
		result = (char *)malloc(sizeof(char) * (ft_strlen(result) + ft_strlen(read_text)));

		ft_strcat(result, read_text);
		printf("result :%s\n", result);
	}

	return text;
}

int main(void)
{
	int fd;
	char *s;

	fd = open("mytext.txt", O_RDONLY);
	s = get_next_line(fd);
	printf("%s\n", s);
	// s = get_next_line(fd);
	// printf("%s\n", s);
	// s = get_next_line(fd);
	// printf("%s\n", s);
	// s = get_next_line(fd);
	// printf("%s\n", s);
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