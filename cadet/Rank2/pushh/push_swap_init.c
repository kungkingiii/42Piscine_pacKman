/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:19:05 by chongsen          #+#    #+#             */
/*   Updated: 2024/03/25 19:13:54 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

void	set_current_position(t_stack_number *stack)
{
	int	i;
	int	centerline;

	i = 0;
	if (NULL == stack)
		return ;
	centerline = stack_len(stack) / 2;
	while (stack)
	{
		stack->current_position = i;
		if (i <= centerline)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

static void	set_target_number(t_stack_number *a,
							t_stack_number *b)
{
	t_stack_number	*current_a;
	t_stack_number	*target_number;
	long			best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value
				&& current_a->value < best_match_index)
			{
				best_match_index = current_a->value;
				target_number = current_a;
			}
			current_a = current_a->next;
		}
		if (LONG_MAX == best_match_index)
			b->target_number = find_smallest(a);
		else
			b->target_number = target_number;
		b = b->next;
	}
}

void	set_price(t_stack_number *a, t_stack_number *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->push_count = b->current_position;
		if (!(b->above_median))
			b->push_count = len_b - (b->current_position);
		if (b->target_number->above_median)
			b->push_count += b->target_number->current_position;
		else
			b->push_count += len_a - (b->target_number->current_position);
		b = b->next;
	}
}

void	set_cheapest(t_stack_number *b)
{
	long			best_match_value;
	t_stack_number	*best_match_number;

	if (NULL == b)
		return ;
	best_match_value = LONG_MAX;
	while (b)
	{
		if (b->push_count < best_match_value)
		{
			best_match_value = b->push_count;
			best_match_number = b;
		}
		b = b->next;
	}
	best_match_number->cheapest = true;
}

void	init_numbers(t_stack_number *a, t_stack_number *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_number(a, b);
	set_price(a, b);
	set_cheapest(b);
}
