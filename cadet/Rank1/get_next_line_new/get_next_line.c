/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 09:56:49 by prossi            #+#    #+#             */
/*   Updated: 2024/02/28 19:15:00 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"	
// #include "get_next_line_utils.c"
#include <fcntl.h>
#include <stdio.h>

// #define BUFFER_SIZE 300
char	*check_end_line(const char *s, char i)
{
	if (i == '\0')
		return ((char *)s);
	while (*s)
	{
	
		if (*s == i)
			return ((char *)s);
		s++;
	}
	return (0);
}

int	check_new_line(char *keep_text)
{
	size_t	count;

	count = 0;
	
	while (keep_text[count] != '\n' && keep_text[count] != '\0')
	{
		// printf("   free %c" ,keep_text[count]);
		count++;
	}
	
	return (count);
}

char	*get_back_up(char *keep_text, int count)
{
	char	*dup_text;
	
	dup_text = keep_text;
	if (keep_text[1] == '\0')
		count = count + 1;
	// printf("dup_text %s",dup_text);
	keep_text = ft_substr(dup_text, count + 1, ft_strlen(dup_text) - count);
	// printf("keep_text %s",keep_text);
	if (!keep_text)
	{
		// printf("   free2 %p\n", keep_text);
		free(keep_text);
		keep_text = NULL;
		return (0);
	}

	return (keep_text);
}

char	*get_line(char *keep_text, int fd)
{
	char	*text;
	int		read_line;

	read_line = 1;
	text = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	
	if (!text)
		return (NULL);
	while (read_line)
	{
		read_line = read(fd, text, BUFFER_SIZE);
		// printf("malloc :%s\n", text);
		if (read_line == -1)
			return (0);
		else if (read_line == 0)
		{
			// printf("read_line :%s\n", text);
			break ;
		}
		text[read_line] = '\0';
		if (!keep_text)
			keep_text = ft_strdup("");
		keep_text = ft_strjoin(keep_text, text);
		// printf("   free1 %s", keep_text);
		if (!keep_text)
		{
			free (keep_text);
			return (NULL);
		}
		if (check_end_line (text, '\n'))
			break ;
	}
	free(text);
	
	return (keep_text);
}

char	*get_next_line(int fd)
{
	static char	*keep_text;
	char		*dup_text;
	char		*line;
	int			count;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (keep_text)
	{
		dup_text = ft_strdup(keep_text);
		if (check_end_line (dup_text, '\0'))
			keep_text = get_line(dup_text, fd);
	}
	else
		keep_text = get_line(keep_text, fd);

	
	if (!keep_text)
	{
		free (keep_text);
		keep_text = NULL;
		return (NULL);
	}
	
	if (check_end_line (keep_text, '\n'))
	{
		
		count = check_new_line(keep_text);	
		line = ft_strdup(keep_text);
		line = ft_substr(line, 0, count + 1);	
		
		if (!line)
		{
		// printf("   free3 %p\n", keep_text);
			free(line);
			return (NULL);
		}
		keep_text = get_back_up(keep_text, count);
		if (!keep_text)
			return (NULL);
		if (*keep_text == '\0')
		{
		// printf("   free2 %p\n", keep_text);
			free(keep_text);
			keep_text = NULL;
		}
	}
	else
	{
		line = keep_text;	
		free(keep_text);
		keep_text = NULL;
	}
// printf("   line %s\n", line);
	return (line);
}


// int	main(void)
// {
//  	int	fd;
//  	char	*s;
	
//  	fd = open("nl", O_RDONLY);
//  	s = get_next_line(fd);
// 	// printf("%s", s);
//  	// s = get_next_line(fd);
// 	// printf("%s", s);
//  	// s = get_next_line(fd);
// 	// printf("%s", s);
//  	// s = get_next_line(fd);
// 	// printf("%s", s);
//  	// s = get_next_line(fd);
// 	// printf("%s", s);

//  	while (s)
//  	{
//  		 printf("%s", s);
//  		free(s);
//  		 s = get_next_line(fd);
//  	 }
//  	free(s);
//  	return (0);
//  }

