/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkrules.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pissrith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 04:38:19 by pissrith          #+#    #+#             */
/*   Updated: 2023/07/23 17:18:42 by pissrith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str);

void	ft_check_rules(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len > 0)
	{
		write(1, "Heelo", 5);
	}
}
