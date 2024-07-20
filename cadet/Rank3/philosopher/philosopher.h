/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: packmanich <packmanich@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 22:32:32 by packmanich        #+#    #+#             */
/*   Updated: 2024/07/20 22:48:44 by packmanich       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>

typedef struct s_philo
{
	pthread_t	thread;
	size_t		time_die;
	size_t		time_eat;
	size_t		time_sleep;
	int			num_of_philo;
	int			times_need_eat;
}	t_philo;

int	ft_atoi(const char *str);