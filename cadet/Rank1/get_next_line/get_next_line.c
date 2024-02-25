/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:35:43 by marvin            #+#    #+#             */
/*   Updated: 2024/02/25 17:47:53 by chongsen         ###   ########.fr       */
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

// char *read_line(char *text, int bytes, int fd)
// {
// 	bytes = read(fd, text, BUFFER_SIZE);
// }
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

char	*check_next_line(char *text, int bytes, int fd,char *result)
{
	int		i;
	char	*line_text;
	char *new_text;



	bytes = read(fd, text, BUFFER_SIZE);
	line_text = (char *)malloc(sizeof(char) * ft_strlen(text) + 1);
	if (!line_text)
	{
		return (0);
	}
		// printf("stringgg cc:%s\n", text);

	i = 0;
	while (text[i])
	{
		// printf("stringgg cc:%c rr%c\n", line_text[i], text[i]);
		if (text[i] == '\n')
		{
			line_text[i] = '\n';
			line_text[i + 1] = '\0';
			// printf("stringgg ee:%s\n", line_text);
			new_text = ft_strjoin(result, line_text);
			// printf("stringgg :%s\n", new_text);stringgg

			return (new_text);
		}
		line_text[i] = text[i];
		// printf("stringgg aa:%s gg%c\n", line_text, text[i]);
		i++;
	}
	// printf("stringgg before:%s\n", result);

	new_text = ft_strjoin(result, line_text);

	new_text = check_next_line(text,bytes,fd ,new_text);
		// printf("stringgg after:%s\n", new_text);stringgg
	// printf("stringgg rraarraa:%c\n", line_text, text[i]);
				// free(line_text);
	return (new_text);
}

// char *check_text(char *text, int bytes, int fd ,char *read_text)
// {
// 	char *result;
// 	int len;

// 	result = read_text;
// 	read_text = check_next_line(text, bytes, fd);
// 				printf("read_text jaa :%s\n" , read_text);
// 	ft_strcat(result, read_text);
// 	len = ft_strlen(read_text);	
// 	if (read_text[len] != '\n')
// 	{
// 		printf("resultttts :%s\n", result);
// 		result = check_text(text,bytes,fd ,result);
// 	}	i = 0;

// 	return result;
// }

char *get_next_line(int fd)
{
	// static t_dat data;
	static char *text;
	char *read_text;
	char *result;
	int bytes;
	int len;
	char *newww;




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

	result = "";

	 newww = check_next_line(text,bytes,fd ,result);

	// read_text = check_next_line(text, bytes, fd);

	// len = ft_strlen(read_text);

	// // ft_strcat(result, read_text);

//  read_text = check_next_line(text, bytes, fd);
	// result = read_text;
	// // printf("result jaa :%s\n", result);

	// if (read_text[len] != '\n')
	//  {
	// 	read_text = check_next_line(text, bytes, fd);
	// 			// printf("read_text jaa :%s\n" , read_text);
	// 	// printf(" result naaa: %s\n ", result);


		// printf("resultttts :%s\n", result);
	// 	ft_strcat(result, read_text);
			// result = check_text(text,bytes,fd ,read_text);
	//  }
	// newww[strlen(newww)] = '\n';newu
	return newww;
}

int main(void)
{
	int fd;
	char *s;

	fd = open("mytext.txt", O_RDONLY);
	s = get_next_line(fd);
	printf("%s", s);
	// s = get_next_line(fd);
	// printf("re%s\n", s);
	// s = get_next_line(fd);
	// printf("re%s\n", s);
	// s = get_next_line(fd);
	// printf("re%s\n", s);
	// s = get_next_line(fd);
	// printf("re%s\n", s);

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