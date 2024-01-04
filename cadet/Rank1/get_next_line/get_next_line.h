/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdanchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:12:29 by kdanchal          #+#    #+#             */
/*   Updated: 2023/12/26 09:51:11 by kdanchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE  3
# endif

typedef struct s_da
{
	char	*s;
	char	*bf;
	char	*nl;
	int		read_f;
	int		error_malloc;
	int		error_join;
}	t_dat;

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strndup(const char *s1, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);

char	*get_next_line(int fd);
char	*gnl2_read_dup(t_dat *data, int fd);
char	*gnl3_join(t_dat *data);
char	*gnl4_result1(t_dat *data);
char	*gnl5_result2(t_dat *data);
void	gnl6_keep(t_dat *data);

#endif
