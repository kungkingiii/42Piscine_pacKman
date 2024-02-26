/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hallykmr <Hallykmr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 09:56:49 by prossi            #+#    #+#             */
/*   Updated: 2024/02/27 00:15:51 by Hallykmr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"	
// #include "get_next_line_utils.c"
#include <fcntl.h>
#include <stdio.h>

// #define BUFFER_SIZE 300
char	*check_end_line(const char *s, int i)
{
	while (*s)
	{
		if (*s == i)
			return ((char *)s);
		s++;
	}
	return (0);
}

static char	*read_line(int fd, char *text, char *keeptext)
{
	int		read_line;
	char	*dup_text;

	read_line = 1;
	while (read_line != '\0')
	{
		read_line = read(fd, text, BUFFER_SIZE);
		if (read_line == -1)
			return (0);
		else if (read_line == 0)
			break ;
		text[read_line] = '\0';
		if (!keeptext)
			keeptext = ft_strdup("");
		dup_text = keeptext;
		keeptext = ft_strjoin(dup_text, text);
		free(dup_text);
		dup_text = NULL;
		if (check_end_line (text, '\n'))
			break ;
	}
	return (keeptext);
}

static char	*check_next_line(char *line)
{
	size_t	count;
	char	*keeptext;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == '\0' || line[1] == '\0')
		return (0);
	keeptext = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (*keeptext == '\0')
	{
		free(keeptext);
		keeptext = NULL;
	}
	line[count + 1] = '\0';
	return (keeptext);
}

char	*get_next_line(int fd)
{
	static char	*keeptext;
	char		*line;
	char		*text;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	text = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!text)
		return (0);
	line = read_line(fd, text, keeptext);
	free(text);
	text = NULL;
	if (!line)
		return (NULL);
	keeptext = check_next_line(line);
	return (line);
}


// int	main(void)
// {
// 	int		fd;
// 	char	*s;

// 	// fd = open("../files/41_with_nl", O_RDONLY);
// 	fd = open("mytext.txt", O_RDONLY);
// 	s = get_next_line(fd);
// 	printf("re: %s", s);
// 	s = get_next_line(fd);
// 	printf("re: %s", s);
// 	s = get_next_line(fd);
// 	printf("re: %s", s);
// 	s = get_next_line(fd);
// 	printf("re: %s", s);
// 	s = get_next_line(fd);
// 	printf("re: %s", s);
// 	// s = get_next_line(fd);
// 	// printf("%s", s);
// 	return (0);
// }
