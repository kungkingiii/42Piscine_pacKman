/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: packmanich <packmanich@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:23:28 by druina            #+#    #+#             */
/*   Updated: 2024/09/12 22:56:21 by packmanich       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_arg_content(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	check_valid_args(char **argv)
{
	if (ft_atoi(argv[1]) > PHILO_MAX || ft_atoi(argv[1]) <= 0
		|| check_arg_content(argv[1]) == 1)
		return (printf("error: invalid number of philo\n"));
	if (ft_atoi(argv[2]) < TIME_MIN || ft_atoi(argv[2]) <= 0
		|| check_arg_content(argv[2]) == 1)
		return (printf("error: invalid time to die\n"));
	if (ft_atoi(argv[3]) < TIME_MIN || ft_atoi(argv[3]) <= 0
		|| check_arg_content(argv[3]) == 1)
		return (printf("error: invalid time to eat\n"));
	if (ft_atoi(argv[4]) < TIME_MIN || ft_atoi(argv[4]) <= 0
		|| check_arg_content(argv[4]) == 1)
		return (printf("error: invalid time to sleep\n"));
	if (argv[5] && (ft_atoi(argv[5]) < 0 || check_arg_content(argv[5]) == 1))
		return (printf("error: invalid times must eat\n"));
	return (0);
}

int	main(int argc, char **argv)
{
	t_program		program;
	t_philo			philos[PHILO_MAX];
	pthread_mutex_t	forks[PHILO_MAX];

	if (argc != 5 && argc != 6)
		return (printf("error: argument should be 4 or 5 \n"));
	if (check_valid_args(argv) == 1)
		return (1);
	init_program(&program, philos);
	init_forks(forks, ft_atoi(argv[1]));
	init_philos(philos, &program, forks, argv);
	thread_create(&program, forks);
	destory_all(NULL, &program, forks);
	return (0);
}
