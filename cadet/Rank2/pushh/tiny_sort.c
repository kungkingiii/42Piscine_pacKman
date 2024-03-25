/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:29:48 by chongsen          #+#    #+#             */
/*   Updated: 2024/03/25 17:48:01 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

bool	first_is_less(t_stack_number *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

static	t_stack_number	*find_highest(t_stack_number *stack)
{
	int				highest;
	t_stack_number	*highest_number;

	if (NULL == stack)
		return (NULL);
	highest = INT_MIN;
	while (stack)
	{
		if (stack->value > highest)
		{
			highest = stack->value;
			highest_number = stack;
		}
		stack = stack->next;
	}
	return (highest_number);
}

void	handle_three(t_stack_number **a)
{
	t_stack_number	*highest_number;

	highest_number = find_highest(*a);
	if (*a == highest_number)
		ra(a, false);
	else if ((*a)->next == highest_number)
		rra(a, false);
	if ((*a)->value > (*a)->next->value)
		sa(a, false);
}

void	handle_five(t_stack_number **a, t_stack_number **b)
{
	while (stack_len(*a) > 3)
	{
		init_numbers(*a, *b);
		finish_rotation(a, find_smallest(*a), 'a');
		pb(b, a, false);
	}
}
