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

typedef struct s_da
{
    char *s;
    char *bf;
    char *nl;
    int read_f;
    int error_malloc;
    int error_join;
} t_dat;

char *get_next_line(int fd)
{
    static t_dat data;
    // char *res;

    data.s = "gg";

    printf("%s", data);
    printf("%d", fd);

    // if (fd < 0 || BUFFER_SIZE < 1)
    // 	return (NULL);
    // data.bf = (char *)malloc(BUFFER_SIZE + 1);
    // if (!data.bf)
    // 	data.error_malloc = 1;
    // if (!data.nl && !data.error_malloc)
    // {
    // 	if (!gnl2_read_dup(&data, fd))
    // 		return (NULL);
    // }
    // free(data.bf);
    // res = gnl4_result1(&data);
    // return (res);
    return "aaa";
}

int main(void)
{
    int fd;
    char *s;

    fd = open("mytext.txt", O_RDONLY);
    s = get_next_line(fd);
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