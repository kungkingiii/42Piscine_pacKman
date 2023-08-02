/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 10:50:09 by chongsen          #+#    #+#             */
/*   Updated: 2023/08/02 10:38:21 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;

	if (min >= max)
	{
		return (0);
	}
	arr = (int *)malloc((max - min) * sizeof(int));
	i = 0;
	if (!arr)
		return (0);
	while (i < max - min)
	{
		arr[i] = min + i;
		i++;
	}
	return (arr);
}
/*int main()
{
     int *arr;
     ft_range(5, 25);
     for (int i = 0; i < 20; i++)
     printf("%d\n", arr[i]);
}*/
