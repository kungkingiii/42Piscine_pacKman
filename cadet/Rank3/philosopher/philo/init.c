/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: packmanich <packmanich@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 21:46:26 by packmanich        #+#    #+#             */
/*   Updated: 2024/07/21 22:18:57 by packmanich       ###   ########.fr       */
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
