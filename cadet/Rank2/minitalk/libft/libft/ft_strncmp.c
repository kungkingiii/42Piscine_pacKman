/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:40:49 by chongsen          #+#    #+#             */
/*   Updated: 2023/10/22 20:35:14 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (str1[i] != '\0' && str2[i] == '\0' && n != 0)
	{
		return (((unsigned char)str1[i]) - 0);
	}
	while (i < n && (str2[i] != '\0' || str1[i] != '\0'))
	{
		if (str1[i] != str2[i])
			return (((unsigned char)str1[i]) - ((unsigned char)str2[i]));
		i++;
	}
	return (0);
}
