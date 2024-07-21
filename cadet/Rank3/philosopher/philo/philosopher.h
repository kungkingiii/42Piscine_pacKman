/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: packmanich <packmanich@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 22:32:32 by packmanich        #+#    #+#             */
/*   Updated: 2024/07/21 22:33:05 by packmanich       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <pthread.h>

# define PHILO_MAX 200

typedef struct s_philo
{
	pthread_t	thread;
	size_t		time_die;
	size_t		time_eat;
	size_t		time_sleep;
	int			num_of_philo;
	int			times_need_eat;
}	t_philo;

typedef struct s_mutex
{
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philo			t_program;
}	t_mutex;

int		ft_atoi(const char *str);
void	init_program(t_mutex *mutex, t_philo *philos);

#endif