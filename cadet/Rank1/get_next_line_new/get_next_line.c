/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hallykmr <Hallykmr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 09:56:49 by prossi            #+#    #+#             */
/*   Updated: 2024/02/28 11:07:53 by Hallykmr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"	
// #include "get_next_line_utils.c"
#include <fcntl.h>
#include <stdio.h>

// #define BUFFER_SIZE 300

// char *read_line()
// {
// 	char *text;
// 	text = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	read_line = read(fd, text, BUFFER_SIZE);
// }

// char *check_new_line(char *read_text)
// {
// 	int i
// }

char	*get_next_line(int fd)
{
	static char	*keeptext;
	char		**line;
	int		read_line;
	// char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	keeptext = "ggg";
	**line = *keeptext;
	printf("line%p : %s\n",line,*line);
	printf("text%p: %s\n",keeptext,keeptext);
	


	// if(keeptext)
	// {
		
	// }
	return(*line);
}


int	main(void)
{
 	int	fd;
 	char	*s;
	
 	fd = open("multiple_nl.txt", O_RDONLY);
 	s = get_next_line(fd);
 	printf("%s", s);
 	// s = get_next_line(fd);
 	// printf("%s", s);
 	// s = get_next_line(fd);
 	// printf("%s", s);
 	// while (s)
 	// {
 		// printf("%s", s);
 		free(s);
 		// s = get_next_line(fd);
 	// }
 	// free(s);
 	return (0);
 }

