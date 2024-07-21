/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: packmanich <packmanich@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 22:04:11 by packmanich        #+#    #+#             */
/*   Updated: 2024/07/21 22:31:41 by packmanich       ###   ########.fr       */
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

int	check_input(char **argv)
{
	if (ft_atoi(argv[1]) > PHILO_MAX || ft_atoi(argv[1]) <= 0
		|| check_is_num(argv[1]) == 1)
		return (1);
	if (ft_atoi(argv[2]) <= 0 || check_is_num(argv[2]) == 1)
		return (1);
	if (ft_atoi(argv[3]) <= 0 || check_is_num(argv[3]) == 1)
		return (1);
	if (ft_atoi(argv[4]) <= 0 || check_is_num(argv[4]) == 1)
		return (1);
	if (argv[5] && (ft_atoi(argv[5]) < 0 || check_is_num(argv[5]) == 1))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo			philos[PHILO_MAX];
	t_mutex			mutex;
	pthread_mutex_t	forks[PHILO_MAX];

	i = 1;
	if (argc != 6 && argc != 5)
		return (printf("error: argument should be 4 or 5 \n"));
	if (check_input(argv) == 1)
		return (1);
	init_program(&mutex, philos);
}
