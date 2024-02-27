/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 09:56:49 by prossi            #+#    #+#             */
/*   Updated: 2024/02/27 20:56:45 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"	
// #include "get_next_line_utils.c"
#include <fcntl.h>
#include <stdio.h>

// #define BUFFER_SIZE 300
char	*check_end_line(const char *s, char i)
{
	while (*s)
	{
		if (*s == i)
			return ((char *)s);
		s++;
	}
	return (0);
}

char	*join_text(char *keeptext, char *text)
{
	char	*dup_text;

	dup_text = keeptext;	
	keeptext = ft_strjoin(dup_text, text);
	// printf("		free : %p\n",dup_text);
	free(dup_text);
	return (keeptext);
}

char	*read_line(int fd, char *text, char **keeptext_ref)
{
	int	read_line;
	char	*keeptext;
	char	*tmp;
	// char	*dup_text;

	keeptext = *keeptext_ref;
	read_line = 1;
	while (read_line != '\0')
	{
		read_line = read(fd, text, BUFFER_SIZE);
		if (read_line == -1 )
		{
			// printf("		free : %p\n",keeptext);
			free(keeptext);
			*keeptext_ref = NULL;
			return (0);
		}
		else if (read_line == 0)
		{
			// tmp = keeptext;
			// keeptext = ft_strjoin(tmp, text);
			// free(tmp);
			*keeptext_ref = NULL;
			break ;
		}
		text[read_line] = '\0';
		if (!keeptext)
		{
			keeptext = ft_strdup("");
			if (!keeptext)
			{
				// printf("		free : %p\n",keeptext);
				free(keeptext);
				*keeptext_ref = NULL;
				return (0);
			}
		}
		// keeptext = join_text(keeptext, text);
		tmp = keeptext;
		keeptext = ft_strjoin(tmp, text);
		// printf("		free : %p\n",tmp);
		free(tmp);
		if (!keeptext)
		{
			// printf("		free : %p\n",keeptext);
			free(keeptext);
			keeptext = NULL;
			return (0);
		}
		if (check_end_line (text, '\n'))
			break ;
	}
	return (keeptext);
}

char	*check_next_line(char *line)
{
	size_t	count;
	char	*keeptext;
	char	*tmp;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == '\0' || line[1] == '\0')
		return (0);
	tmp = line;
	keeptext = ft_substr(tmp, count + 1, ft_strlen(tmp) - count);
	
	// free (tmp);
	if (!keeptext)
	{
		// printf("		free : %p\n",keeptext);
		free(keeptext);
		keeptext = NULL;
		return (0);
	}
	if (*keeptext == '\0')
	{
		// printf("		free : %p\n",keeptext);
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
	// char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	text = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	// printf("malloc : %p\n",text);
	if (!text)
	{
		free (keeptext);
		keeptext = NULL;
		return (NULL);	
	}
	
	line = read_line(fd, text, &keeptext);
	// printf("		free : %p\n",text);
	free(text);
	// text = NULL;
	if (!line)
		return (NULL);		
	keeptext = check_next_line(line);
	return (line);
}


// int	main(void)
// {
//  	int	fd;
//  	char	*s;
	
//  	fd = open("multiple_nl.txt", O_RDONLY);
//  	s = get_next_line(fd);
//  	printf("%s", s);
//  	while (s)
//  	{
//  		printf("%s", s);
//  		free(s);
//  		s = get_next_line(fd);
//  	}
//  	free(s);
//  	return (0);
//  }

