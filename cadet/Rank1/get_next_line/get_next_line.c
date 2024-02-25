/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:35:43 by marvin            #+#    #+#             */
/*   Updated: 2024/02/25 19:06:46 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUFFER_SIZE 3

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


static size_t	ft_strcpy(char *dest, const char *src, size_t size)
{
	size_t	n;

	n = 0;
	while (src[n] != '\0')
	{
		dest[size] = src[n];
		size++;
		n++;
	}
	return (n);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;
	size_t	i;
	size_t	n;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(len + 1 * sizeof(char));
	if (!str)
	{
		return (0);
	}
	n = ft_strcpy(str, s1, i);
	ft_strcpy(str, s2, n);
	str[len] = '\0';
	return (str);
}

char	*ft_strdup(const char *str)
{
	char	*ptr;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	ptr = (char *)malloc(len + 1 * sizeof(char));
	if (!ptr)
		return (0);
	while (str[i] != '\0')
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

void move_text(char *dup_text, char *text, int dest)
{
	int i;

	i = 0;
		while (dup_text[dest])
		{	
			text[i] = dup_text[dest];
			printf("this is dup: %c text%c\n",text[i],dup_text[i]);
			i++;
			dest++;
		}
}

char	*check_next_line(char *text, int bytes, int fd,char *result)
{
	int		i;
	char	*line_text;
	char *dup_text;
	char *new_text;

	bytes = read(fd, text, BUFFER_SIZE);
	dup_text = ft_strdup(text);
	line_text = (char *)malloc(sizeof(char) * ft_strlen(dup_text) + 1);
	if (!line_text)
	{
		return (0);
	}
	i = 0;
	while (dup_text[i])
	{
		if (dup_text[i] == '\n')
		{
			line_text[i] = '\n';
			line_text[i + 1] = '\0';
			new_text = ft_strjoin(result, line_text);
			if(dup_text[i+1] == '\0')
			{
				text = NULL;
				printf("texttt%s",text);
			}
				// move_text(dup_text,text,i + 1);
			return (new_text);
		}
		line_text[i] = dup_text[i];
		i++;
	}
	new_text = ft_strjoin(result, line_text);
	new_text = check_next_line(text,bytes,fd ,new_text);
	return (new_text);
}



char *get_next_line(int fd)
{
	static char *text;
	char *read_text;
	char *result;
	int bytes;
	int len;
	char *newww;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);

		printf("this is text: %s\n",text);


	text = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));


	result = "";
	 newww = check_next_line(text,bytes,fd ,result);
	return newww;
}

int main(void)
{
	int fd;
	char *s;

	fd = open("mytext.txt", O_RDONLY);
	s = get_next_line(fd);
	printf("%s", s);
	s = get_next_line(fd);
	printf("%s", s);
	s = get_next_line(fd);
	printf("%s", s);
	return (0);
}