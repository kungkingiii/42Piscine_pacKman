/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: packmanich <packmanich@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 22:04:11 by packmanich        #+#    #+#             */
/*   Updated: 2024/07/22 22:10:35 by packmanich       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosopher.h"

int	check_is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (printf("error: argument not number: %s\n", str));
		i++;
	}
	return (0);
}

int	check_is_zero(char *str)
{
	if (ft_atoi(str) <= 0)
		return (printf("error: argument should be more than 0\n"));
	return (0);
}

int	check_input(char **argv)
{
	if (ft_atoi(argv[1]) > PHILO_MAX || check_is_zero(argv[1]) == 1
		|| check_is_num(argv[1]) == 1)
		return (printf("error: invalid number of philo\n"));
	if (ft_atoi(argv[2]) < TIME_MIN || check_is_zero(argv[2]) == 1
		|| check_is_num(argv[2]) == 1)
		return (printf("error: invalid time to die\n"));
	if (ft_atoi(argv[3]) < TIME_MIN || check_is_zero(argv[3]) == 1
		|| check_is_num(argv[3]) == 1)
		return (printf("error: invalid time to eat\n"));
	if (ft_atoi(argv[4]) < TIME_MIN || check_is_zero(argv[4]) == 1
		|| check_is_num(argv[4]) == 1)
		return (printf("error: invalid time to sleep\n"));
	if (argv[5] && (ft_atoi(argv[5]) < 0 || check_is_num(argv[5]) == 1))
		return (printf("error: invalid times must eat\n"));
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo			philos[PHILO_MAX];
	t_mutex			mutex;
	pthread_mutex_t	forks[PHILO_MAX];

	if (argc != 6 && argc != 5)
		return (printf("error: argument should be 4 or 5 \n"));
	if (check_input(argv) == 1)
		return (1);
	init_program(&mutex, philos);
	init_forks(forks, ft_atoi(argv[1]));
	init_philos(philos, &mutex, forks, argv);
	create_thread(&mutex, forks);
}
