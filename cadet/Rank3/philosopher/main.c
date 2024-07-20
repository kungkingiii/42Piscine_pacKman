/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: packmanich <packmanich@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 22:04:11 by packmanich        #+#    #+#             */
/*   Updated: 2024/07/20 23:00:07 by packmanich       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosopher.h"

t_philo	*check_input(char *str)
{
	t_philo	*philo;

	philo->num_of_philo = ft_atoi(str);
	printf("argv%i\n", philo->num_of_philo);
	return (philo);
}

int	main(int argc, char **argv)
{
	int		i;
	t_philo	*philo;

	i = 0;
	printf("argc%i\n", argc);
	if (argc != 6 && argc != 5)
		return (0);
	while (argv[i])
	{
		philo = check_input(argv[i]);
		i++;
	}
}
