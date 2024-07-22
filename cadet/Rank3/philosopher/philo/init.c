/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: packmanich <packmanich@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 21:46:26 by packmanich        #+#    #+#             */
/*   Updated: 2024/07/22 13:22:25 by packmanich       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosopher.h"

void	init_program(t_mutex *mutex, t_philo *philos)
{
	mutex->dead_flag = 0;
	mutex->philos = philos;
	pthread_mutex_init(&mutex->write_lock, NULL);
	pthread_mutex_init(&mutex->dead_lock, NULL);
	pthread_mutex_init(&mutex->meal_lock, NULL);
}

void	init_forks(pthread_mutex_t *forks, int forks_num)
{
	int	i;

	i = 0;
	while (i < forks_num)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	init_input(t_philo *philos, char **argv)
{
	philos->time_die = ft_atoi(argv[2]);
	philos->time_eat = ft_atoi(argv[3]);
	philos->time_sleep = ft_atoi(argv[4]);
	philos->num_of_philos = ft_atoi(argv[1]);
	if (argv[5])
		philos->times_need_eat = ft_atoi(argv[5]);
	else
		philos->times_need_eat = -1;
}

void	init_philos(t_philo *philos, t_mutex *mutex
, pthread_mutex_t *forks, char **argv)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		init_input(&philos[i], argv);
		philos[i].id = i + 1;
		philos[i].eating = 0;
		philos[i].meals_eaten = 0;
		philos[i].start_time = get_current_time();
		philos[i].last_meal = get_current_time();
		philos[i].write_lock = &mutex->write_lock;
		philos[i].dead_lock = &mutex->dead_lock;
		philos[i].meal_lock = &mutex->meal_lock;
		philos[i].dead = &mutex->dead_flag;
		philos[i].left_fork = &forks[i];
		if (i == 0)
			philos[i].right_fork = &forks[philos[i].num_of_philos - 1];
		else
			philos[i].right_fork = &forks[i - 1];
		i++;
	}
}
