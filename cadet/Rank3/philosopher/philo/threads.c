/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:10:19 by packmanich        #+#    #+#             */
/*   Updated: 2024/07/24 10:26:05 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosopher.h"

// int	thread_create(t_program *program, pthread_mutex_t *forks)
// {
// 	pthread_t	observer;
// 	int			i;

// 	if (pthread_create(&observer, NULL, &monitor, program->philos) != 0)
// 		destory_all("Thread creation error", program, forks);
// 	i = 0;
// 	while (i < program->philos[0].num_of_philos)
// 	{
// 		if (pthread_create(&program->philos[i].thread, NULL, &philo_routine,
// 				&program->philos[i]) != 0)
// 			destory_all("Thread creation error", program, forks);
// 		i++;
// 	}
// 	i = 0;
// 	if (pthread_join(observer, NULL) != 0)
// 		destory_all("Thread join error", program, forks);
// 	while (i < program->philos[0].num_of_philos)
// 	{
// 		if (pthread_join(program->philos[i].thread, NULL) != 0)
// 			destory_all("Thread join error", program, forks);
// 		i++;
// 	}
// 	return (0);
// }

int	create_thread(t_mutex *mutex, pthread_mutex_t *forks)
{
	int			i;
	pthread_t	philo_thread;

	i = 0;
	while (i < mutex->philos[0].num_of_philos)
	{
		pthread_create(&mutex->philos[i].thread, NULL,
			&philo_routine, &mutex->philos[i]);
		i++;
	}
	i = 0;
	while (i < mutex->philos[0].num_of_philos)
		pthread_join(mutex->philos[i].thread, NULL);
	{
		i++;
	}
	return (0);
}
