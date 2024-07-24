/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 22:32:32 by packmanich        #+#    #+#             */
/*   Updated: 2024/07/24 09:59:49 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>

# define PHILO_MAX 200
# define TIME_MIN 60

typedef struct s_philo
{
	pthread_t		thread;
	size_t			time_die;
	size_t			time_eat;
	size_t			time_sleep;
	size_t			start_time;
	size_t			last_meal;
	int				num_of_philos;
	int				times_need_eat;
	int				id;
	int				eating;
	int				meals_eaten;
	int				*dead;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}	t_philo;

typedef struct s_mutex
{
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philo			*philos;
}	t_mutex;

int		ft_atoi(const char *str);
int		ft_usleep(size_t milliseconds);
void	init_program(t_mutex *mutex, t_philo *philos);
void	init_forks(pthread_mutex_t *forks, int forks_num);
void	init_philos(t_philo *philos, t_mutex *mutex,
			pthread_mutex_t *forks, char **argv);
size_t	get_current_time(void);
int		create_thread(t_mutex *mutex, pthread_mutex_t *forks);
void	*philo_routine(void *one_philo);

#endif