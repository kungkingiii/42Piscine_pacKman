/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hallykmr <Hallykmr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:35:43 by marvin            #+#    #+#             */
/*   Updated: 2024/02/26 23:52:57 by Hallykmr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"
#include "get_next_line_utils.c"

// #define BUFFER_SIZE 300

void	move_text(char *text, int dest)
{
	int		i;
	char	*dup_text;

	dup_text = ft_strdup(text);
	i = 0;
	while (dup_text[dest])
	{	
		text[i] = dup_text[dest];
		i++;
		dest++;
	}
	text[i] = '\0';
}

char	*check_next_line(char *text, int bytes, int fd, char *result)
{
	int		i;
	char	*line_text;
	char	*new_text;

	bytes = read(fd, text, BUFFER_SIZE);
	line_text = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	line_text[bytes] = '\0';
	if (!line_text || bytes == -1 || !text)
		return (NULL);
	i = 0;
	while (text[i])
	{
		if (text[i] == '\n')
		{
			line_text[i] = '\n';
			line_text[i + 1] = '\0';
			new_text = ft_strjoin(result, line_text);
			return (new_text);
		}
		line_text[i] = text[i];
		i++;
	}
	new_text = ft_strjoin(result, line_text);
	new_text = check_next_line(text, bytes, fd, new_text);
	return (new_text);
}

char	*find_next(char *text, int bytes, int fd, int dest)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (text[dest])
	{
		if (text[dest] == '\n' && text[dest + 1] != '\0')
		{
			// printf("this is text 2: %s str: %s dest: %c", text, str, text[dest] );
			move_text(text, dest);
			// printf("strrrr: %s",str);
			str[i] = '\n';
			str[i + 1] = '\0';
			return (str);
		}
		// printf("this is text 3: %s text:%c\n",str, text[dest]);
		str[i] = text[dest];
		i++;
		dest++;
	}
	str[i] = '\0';
	// printf("strrrr3: %s", str);
	if (str && str[i + 1] != '\n')
	{
					// printf("strrrr2: %s",str);
		str = check_next_line(text, bytes, fd, str);
		return (str);
	}
	return (str);
}

char	*check_line(char *text, int bytes, int fd)
{
	int		i;
	char	*str;

	i = 0;
	while (text[i])
	{
		if (text[i] == '\n' && text[i + 1] != '\0')
		{
			printf("this is text : %s\n", text);
			str = find_next(text, bytes, fd, i + 1);
			return (str);
		}
		i++;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*text;
	char		*result;
	char		*first_text;
	int			bytes;

	result = NULL;
	// result = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	bytes = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (text)
		result = check_line(text, bytes, fd);
	if (!result)
	{		
		text = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!text)
			return (NULL);
		first_text = "";
		result = check_next_line(text, bytes, fd, first_text);
	}
	return (result);
}


int	main(void)
{
	int		fd;
	char	*s;

	// fd = open("../files/41_with_nl", O_RDONLY);
	fd = open("mytext.txt", O_RDONLY);
	s = get_next_line(fd);
	printf("re: %s", s);
	s = get_next_line(fd);
	printf("re: %s", s);
	s = get_next_line(fd);
	printf("re: %s", s);
	s = get_next_line(fd);
	printf("re: %s", s);
	s = get_next_line(fd);
	printf("re: %s", s);
	// s = get_next_line(fd);
	// printf("%s", s);
	return (0);
}
