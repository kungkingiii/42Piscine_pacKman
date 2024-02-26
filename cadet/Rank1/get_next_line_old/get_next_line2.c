/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hallykmr <Hallykmr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:35:43 by marvin            #+#    #+#             */
/*   Updated: 2024/02/26 23:12:23 by Hallykmr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"
#include "get_next_line_utils.c"

char *read_line()
{
	
}

char	*get_next_line(int fd)
{
	static char	*text;
	char		*result;
	char		*first_text;
	int			bytes;

	result = NULL;
	// result = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	bytes = 0;
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
