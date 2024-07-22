/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: packmanich <packmanich@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 22:48:02 by packmanich        #+#    #+#             */
/*   Updated: 2024/07/22 13:28:26 by packmanich       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosopher.h"

static int	ft_count(char *str, int i, int count, int toi)
{
	int	a;

	a = str[i] - '0';
	toi = toi + a;
	if (str[i + 1] < 48 || str[i + 1] > 57)
	{
		if (count == 1)
		{
			toi = toi * -1;
		}
	}
	else
	{
		toi = toi * 10;
	}
	return (toi);
}

static int	checkcount(char c)
{
	if (c == 45)
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	toi;
	int	count;

	i = -1;
	toi = 0;
	count = 0;
	while (str[++i] != '\0')
	{
		if (str[i] > 47 && str[i] < 58)
		{
			toi = ft_count((char *)str, i, count, toi);
			if (str[i + 1] < 48 || str[i + 1] > 57)
				return (toi);
		}
		else if (str[i] == 45 || str[i] == 43)
		{
			if (str[i + 1] < 48 || str[i + 1] > 57)
				return (toi);
			count = checkcount(str[i]);
		}
		else if (str[i] < 9 || (str[i] > 13 && str[i] != 32))
			return (toi);
	}
	return (toi);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		printf("error: can't get time with some reason\n");
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
