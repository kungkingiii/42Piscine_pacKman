/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:32:59 by packmanich        #+#    #+#             */
/*   Updated: 2024/07/24 10:29:27 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosopher.h"

void	eat_action(t_philo *philo)
{
	size_t	time;

	time = get_current_time() - philo->start_time;
	printf("%zu %d has taken a fork\n", time, philo->id);
	printf("%zu %d has taken a fork\n", time, philo->id);
	printf("%zu %d is eating\n", time, philo->id);
	philo->eating += 1;
}

void	dream_action(t_philo *philo)
{
	size_t	time;
	size_t	eat_time;

	time = get_current_time() - philo->start_time;
	eat_time = time + philo->time_eat;
	printf("%zu %d is sleeping\n", eat_time, philo->id);
}

void	think_action(t_philo *philo)
{
	size_t	time;
	size_t	think_time;
	size_t	die_time;

	time = get_current_time() - philo->start_time;
	die_time = philo->time_die * philo->eating;
	think_time = time + philo->time_eat + philo->time_sleep;
	if (think_time > die_time)
		printf("%zu %d died\n", die_time, philo->id);
	else
		printf("%zu %d is thinking\n", think_time, philo->id);
}

void	*philo_routine(void *one_philo)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = (t_philo *)one_philo;
	while (i < philo->times_need_eat)
	{
		eat_action(philo);
		dream_action(philo);
		think_action(philo);
		i++;
	}
	return (0);
}
