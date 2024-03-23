/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utente <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 09:42:38 by utente            #+#    #+#             */
/*   Updated: 2023/04/05 10:54:02 by utente           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

/*
 *  atol, i need it to check eventual overflows
 *  converting every string into a long value
 */
static long ft_atol(const char *str)
{
	long num;
	int negative;
	int i;

	num = 0;
	negative = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		negative *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * negative);
}

void stack_init(t_stack_node **a, char **argv, bool argc_status)
{
	long nbr;
	int i;

	i = 0;

	while (argv[i])
	{
		if (error_syntax(argv[i]))
			error_free(a, argv, argc_status);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a, argv, argc_status);
		if (error_repetition(*a, (int)nbr))
			error_free(a, argv, argc_status);
		append_node(a, (int)nbr);
		++i;
	}
	if (argc_status)
		free_matrix(argv);
}
