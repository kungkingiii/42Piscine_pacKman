/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hallykmr <Hallykmr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 09:09:23 by chongsen          #+#    #+#             */
/*   Updated: 2024/03/24 22:26:12 by Hallykmr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	else if (!argv[1][0])
	{
		write(2, "Error\n", 6);
		return (1);
	}
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	check_error(&a, argv + 1, argc == 2);
	if (!first_is_less(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			handle_three(&a);
		else
			push_swap(&a, &b);
	}
	free_stack(&a);
}
